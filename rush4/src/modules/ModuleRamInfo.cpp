#include "ModuleRamInfo.hpp"
#include "../Metrics.hpp"
#include <cstdint>
#include <string>
#include <sys/types.h>

namespace Krell {

void ModuleRamInfo::update() { return; }

void ModuleRamInfo::draw(IDisplay &display) {
  std::uint64_t total = Metrics::getRamTotalKb() / 1000;
  std::uint64_t used = Metrics::getRamUsedKb() / 1000;
  std::uint64_t free = total - used;
  int x = 1;
  int y = display.getY() + 2;
  int start_y = y;

  display.drawBox(x, y, 50, 11);
  display.drawText(x + 2, y, "Ram Info", true);
  y += 4;
  x += 1;
  display.drawBar(x + 1, y, 1, 48, (used * 100 / total), "RAM");
  display.drawText(x + 1, y += 2,
                   "RAM Usage: " + std::to_string(used) + "MB / " +
                       std::to_string(total) + "MB, " + std::to_string(free) +
                       "MB free.");
  display.setY(start_y + 10);
  if (this->_queue.size() == RAM_QUEUE_SIZE)
    this->_queue.pop_back();
  this->_queue.push_front(used * 100 / total);
  display.drawGraph(53, 28, 25, 187, RAM_QUEUE_SIZE, this->_queue, "RAM Usage");
}

} // namespace Krell
