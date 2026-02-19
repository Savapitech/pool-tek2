#include "ModuleSystemInfo.hpp"
#include "../Metrics.hpp"

namespace Krell {

ModuleSystemInfo::ModuleSystemInfo() {
  _hostname = Metrics::getHostname();
  _username = Metrics::getUsername();
  _os = Metrics::getOs();
  _kernel = Metrics::getKernel();
  _time = Metrics::getTime();
  _date = Metrics::getDate();
}

void ModuleSystemInfo::update() {
  _time = Metrics::getTime();
  _date = Metrics::getDate();
}

void ModuleSystemInfo::draw(IDisplay &display) {
  std::string user = "Username:  " + _username;
  std::string host = "Hostname:  " + _hostname;
  std::string os = "Op. sys.:  " + _os;
  std::string kernel = "Kernel:  " + _kernel;
  int y = display.getY() + 2;
  int start_y = y;
  int x = 1;
  display.drawBox(x, y, 50, 14);
  display.drawText(x + 2, y, "System Info", true);
  y++;
  display.drawText(3, y += 3, user);
  display.drawText(3, y += 2, host);
  display.drawText(37, y, _date);
  display.drawText(3, y += 2, os);
  display.drawText(39, y, _time);
  display.drawText(3, y += 2, kernel);
  display.setY(start_y + 14);
}

} // namespace Krell
