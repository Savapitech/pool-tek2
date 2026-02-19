#include <string>
#include <sys/types.h>

#include "../Metrics.hpp"
#include "ModuleBatteryInfo.hpp"

namespace Krell {

void ModuleBatteryInfo::update() { return; }

void ModuleBatteryInfo::draw(IDisplay &display) {
  int x = 1;
  int y = display.getY() + 2;
  int start_y = y;
  uint8_t battery = Metrics::getBatteryPercentage();

  display.drawBox(x, y, 50, 9);
  display.drawText(x + 2, y, "Battery Info", true);
  y += 4;
  x += 1;
  display.drawBar(x + 1, y, 1, 48, battery, "Battery", true);
  display.setY(start_y + 8);
  if (this->_queue.size() == BATTERY_QUEUE_SIZE)
    this->_queue.pop_back();
  this->_queue.push_front(battery);
  display.drawGraph(53, 55, 25, 187, BATTERY_QUEUE_SIZE, this->_queue,
                    "Battery Usage");
}

} // namespace Krell
