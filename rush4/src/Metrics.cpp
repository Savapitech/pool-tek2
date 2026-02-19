#include <chrono>
#include <cstdint>
#include <ctime>
#include <dirent.h>
#include <fstream>
#include <iomanip>
#include <pwd.h>
#include <set>
#include <stdlib.h>
#include <sys/utsname.h>
#include <thread>
#include <unistd.h>
#include <vector>

#include "Metrics.hpp"

namespace Krell {

std::string Metrics::getUsername() {
  return std::string(getlogin() != nullptr ? getlogin() : "Unknown");
}

std::string Metrics::getHostname() {
  char hostname[128];

  if (gethostname(hostname, sizeof hostname) == 0)
    return std::string(hostname);
  return std::string("Unknown");
}

std::string Metrics::getOs() {
  std::ifstream file("/etc/os-release");
  std::string line;

  while (std::getline(file, line))
    if (line.rfind("PRETTY_NAME=", 0) == 0)
      return line.substr(13, line.size() - 14);
  return std::string("Unknown");
}

std::string Metrics::getKernel() {
  struct utsname utsname;

  if (uname(&utsname) == 0)
    return std::string(utsname.release);
  return std::string("Unknown");
}

std::string Metrics::getTime() {
  auto now = std::chrono::system_clock::now();
  std::time_t t = std::chrono::system_clock::to_time_t(now);

  std::tm tm{};
  localtime_r(&t, &tm);

  std::ostringstream oss;
  oss << std::put_time(&tm, TIME_FORMAT);
  return oss.str();
}

std::string Metrics::getDate() {
  auto now = std::chrono::system_clock::now();
  std::time_t t = std::chrono::system_clock::to_time_t(now);

  std::tm tm{};
  localtime_r(&t, &tm);

  std::ostringstream oss;
  oss << std::put_time(&tm, DATE_FORMAT);
  return oss.str();
}

struct CpuTimes {
  uint64_t idle;
  uint64_t total;
};

std::vector<uint8_t> Metrics::getCpusUsage() {
  static std::vector<CpuTimes> prev;
  std::ifstream file("/proc/stat");
  std::string line;

  std::vector<uint8_t> usage;
  std::vector<CpuTimes> current;

  while (std::getline(file, line)) {
    if (line.rfind("cpu", 0) != 0 || line == "cpu")
      break;

    std::istringstream iss(line);
    std::string cpu;
    uint64_t user, nice, system, idle, iowait, irq, softirq, steal;

    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >>
        steal;

    uint64_t idle_time = idle + iowait;
    uint64_t total_time =
        user + nice + system + idle + iowait + irq + softirq + steal;

    current.push_back({idle_time, total_time});
  }

  if (prev.empty()) {
    prev = current;
    usage.resize(current.size(), 0);
    return usage;
  }

  for (size_t i = 0; i < current.size(); ++i) {
    uint64_t idle_delta = current[i].idle - prev[i].idle;
    uint64_t total_delta = current[i].total - prev[i].total;

    uint8_t percent = 0;
    if (total_delta > 0) {
      percent =
          static_cast<uint8_t>(100 * (total_delta - idle_delta) / total_delta);
    }
    usage.push_back(percent);
  }

  prev = current;
  return usage;
}

std::uint16_t Metrics::getVCpuCount() {
  return static_cast<std::uint16_t>(std::thread::hardware_concurrency());
}

std::uint16_t Metrics::getPCpuCount() {
  std::ifstream file("/proc/cpuinfo");
  std::string line;

  std::set<std::pair<int, int>> cores;
  int physical_id = -1;
  int core_id = -1;

  while (std::getline(file, line)) {
    if (line.rfind("physical id", 0) == 0)
      physical_id = std::stoi(line.substr(line.find(':') + 1));

    if (line.rfind("core id", 0) == 0)
      core_id = std::stoi(line.substr(line.find(':') + 1));

    if (physical_id != -1 && core_id != -1) {
      cores.insert({physical_id, core_id});
      physical_id = -1;
      core_id = -1;
    }
  }

  return static_cast<std::uint16_t>(cores.size());
}

uint64_t Metrics::getRamTotalKb() {
  std::ifstream file("/proc/meminfo");
  std::string line;

  while (std::getline(file, line)) {
    if (line.rfind("MemTotal:", 0) == 0) {
      std::istringstream iss(line);
      std::string key;
      uint64_t value;
      std::string unit;
      iss >> key >> value >> unit;
      return value;
    }
  }
  return 0;
}

uint64_t Metrics::getRamUsedKb() {
  std::ifstream file("/proc/meminfo");
  std::string line;
  uint64_t memAvailable = 0;
  uint64_t memTotal = Metrics::getRamTotalKb();

  while (std::getline(file, line)) {
    if (line.rfind("MemAvailable:", 0) == 0) {
      std::istringstream iss(line);
      std::string key;
      iss >> key >> memAvailable;
      break;
    }
  }

  if (memTotal < memAvailable)
    return 0;

  return memTotal - memAvailable;
}

std::vector<Metrics::Inet> Metrics::getInets() {
  std::vector<Metrics::Inet> inets;
  std::ifstream file("/proc/net/dev");
  std::string line;

  std::getline(file, line);
  std::getline(file, line);

  int i = 0;
  while (std::getline(file, line) && i < 2) {
    std::istringstream iss(line);
    std::string iface;
    if (line.find(":") == std::string::npos)
      continue;

    iface = line.substr(0, line.find(":"));
    iface.erase(std::remove_if(iface.begin(), iface.end(), ::isspace),
                iface.end());

    uint64_t rBytes, rPackets, rErr, rDrop, rFifo, rFrame, rCompressed,
        rMulticast;
    uint64_t tBytes, tPackets, tErr, tDrop, tFifo, tColls, tCarrier,
        tCompressed;

    std::string dummy;
    iss >> dummy;
    iss >> rBytes >> rPackets >> rErr >> rDrop >> rFifo >> rFrame >>
        rCompressed >> rMulticast >> tBytes >> tPackets >> tErr >> tDrop >>
        tFifo >> tColls >> tCarrier >> tCompressed;

    std::string ip = "";

    inets.emplace_back(iface, rPackets, rBytes * 8, rErr, rDrop, tPackets,
                       tBytes * 8, tErr, tDrop, ip);
    i++;
  }

  return inets;
}

std::uint8_t Metrics::getBatteryPercentage() {
  DIR *dir = opendir("/sys/class/power_supply");
  if (!dir)
    return 0;

  struct dirent *entry;

  while ((entry = readdir(dir)) != nullptr) {
    std::string name(entry->d_name);

    if (name.rfind("BAT", 0) != 0)
      continue;

    std::string path = "/sys/class/power_supply/" + name + "/capacity";
    std::ifstream file(path);

    if (!file.is_open())
      continue;

    int capacity = 0;
    file >> capacity;

    closedir(dir);

    if (capacity < 0)
      capacity = 0;
    if (capacity > 100)
      capacity = 100;

    return static_cast<uint8_t>(capacity);
  }

  closedir(dir);
  return 0;
}

std::string Metrics::getCpuName() {
  std::ifstream file("/proc/cpuinfo");
  std::string line;

  while (std::getline(file, line))
    if (line.rfind("model name", 0) == 0)
      return line.substr(line.find(':') + 1);
  return "";
}

std::uint16_t Metrics::getCpuFreq() {
  std::ifstream file("/proc/cpuinfo");
  std::string line;

  while (std::getline(file, line))
    if (line.rfind("cpu MHz", 0) == 0)
      return std::stoi(line.substr(line.find(':') + 1));
  return 0;
}

} // namespace Krell
