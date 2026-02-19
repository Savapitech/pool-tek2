#include "ModuleCpuInfo.hpp"
#include "../Metrics.hpp"
#include <cstdint>
#include <string>

namespace Krell {

void ModuleCpuInfo::update() { return; }

void ModuleCpuInfo::draw(IDisplay &display) {
  std::vector<uint8_t> cpus = Metrics::getCpusUsage();
  std::uint16_t physics = Metrics::getPCpuCount();
  std::uint16_t virtuals = Metrics::getVCpuCount();
  int x = 1;
  int y = display.getY() + 2;
  int start_y = y;

  display.drawBox(x, y, 50, cpus.size() * 2 + 10);
  display.drawText(x + 2, y, "CPU Info |" + Metrics::getCpuName(), true);
  y += 4;
  x += 1;
  display.drawText(x + 1, y,
                   "Physical: " + std::to_string(physics) + ", " +
                       "Virtual: " + std::to_string(virtuals) + ", Freq: " +
                       std::to_string(Metrics::getCpuFreq()) + "Mhz");
  y += 2;
  display.drawBar(x + 1, y, 1, 48, cpus[0], "Total");
  if (this->_queue.size() == CPU_QUEUE_SIZE)
    this->_queue.pop_back();
  this->_queue.push_front(cpus[0]);
  y += 2;
  for (size_t i = 1; i < cpus.size(); ++i)
    display.drawBar(x + 1, y + i * 2, 1, 48, cpus[i],
                    "Core " + std::to_string(i));
  display.setY(start_y + cpus.size() * 2 + 10);
  display.drawGraph(53, 1, 25, 187, CPU_QUEUE_SIZE, this->_queue, "CPU Usage");
}

} // namespace Krell
