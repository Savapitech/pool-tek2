#pragma once

#include <cstdint>
#include <string>
#include <vector>

#define TIME_FORMAT "%H:%M:%S"
#define DATE_FORMAT "%d/%m/%Y"

namespace Krell {

namespace Metrics {
class Inet {
  std::string _name;
  std::string _ip;
  std::uint64_t _receivedPackets;
  std::uint64_t _receivedBits;
  std::uint64_t _receivedError;
  std::uint64_t _receivedDrop;
  std::uint64_t _transmitPackets;
  std::uint64_t _transmitBits;
  std::uint64_t _transmitError;
  std::uint64_t _transmitDrop;

public:
  std::string getIpt() const { return _ip; }
  std::string getName() const { return _name; }
  std::uint64_t getRPackets() const { return _receivedPackets; }
  std::uint64_t getRBits() const { return _receivedBits; }
  std::uint64_t getRError() const { return _receivedError; }
  std::uint64_t getRDrop() const { return _receivedDrop; }
  std::uint64_t getTPackets() const { return _transmitPackets; }
  std::uint64_t getTBits() const { return _transmitBits; }
  std::uint64_t getTError() const { return _transmitError; }
  std::uint64_t getTDrop() const { return _transmitDrop; }
  Inet(const std::string &name, uint64_t rPackets, uint64_t rBits,
       uint64_t rError, uint64_t rDrop, uint64_t tPackets, uint64_t tBits,
       uint64_t tError, uint64_t tDrop, const std::string &ip)
      : _name(name), _ip(ip), _receivedPackets(rPackets), _receivedBits(rBits),
        _receivedError(rError), _receivedDrop(rDrop),
        _transmitPackets(tPackets), _transmitBits(tBits),
        _transmitError(tError), _transmitDrop(rDrop) {}
};

std::string getUsername();
std::string getHostname();
std::string getOs();
std::string getKernel();
std::string getTime();
std::string getDate();
std::vector<std::uint8_t> getCpusUsage();
std::string getCpuName();
std::uint16_t getCpuFreq();
std::uint16_t getVCpuCount();
std::uint16_t getPCpuCount();
std::uint64_t getRamTotalKb();
std::uint64_t getRamUsedKb();
std::vector<Metrics::Inet> getInets();
std::uint8_t getBatteryPercentage();
}; // namespace Metrics

} // namespace Krell
