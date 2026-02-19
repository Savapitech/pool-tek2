#include <iomanip>
#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>

#include "Metrics.hpp"
#include "display/IDisplay.hpp"
#include "display/ncurses/Ncurses.hpp"
#include "display/sfml/SFML.hpp"
#include "modules/IModule.hpp"
#include "modules/ModuleBatteryInfo.hpp"
#include "modules/ModuleCpuInfo.hpp"
#include "modules/ModuleNetworkInfo.hpp"
#include "modules/ModuleRamInfo.hpp"
#include "modules/ModuleSystemInfo.hpp"

int mainLoop(Krell::IDisplay *disp,
             std::vector<std::unique_ptr<Krell::IModule>> &modules) {
  while (disp->getState()) {
    disp->refreshWindow();

    std::vector<int> keys = disp->getKeys();
    for (int key : keys) {
      char k = (char)tolower(key);
      if (k == 'e')
        disp->setState(false);
      for (auto &module : modules) {
        if (k == 'b' &&
            dynamic_cast<Krell::ModuleBatteryInfo *>(module.get())) {
          module->set_state(!module->get_state());
        } else if (k == 's' &&
                   dynamic_cast<Krell::ModuleSystemInfo *>(module.get())) {
          module->set_state(!module->get_state());
        } else if (k == 'c' &&
                   dynamic_cast<Krell::ModuleCpuInfo *>(module.get())) {
          module->set_state(!module->get_state());
        } else if (k == 'r' &&
                   dynamic_cast<Krell::ModuleRamInfo *>(module.get())) {
          module->set_state(!module->get_state());
        } else if (k == 'n' &&
                   dynamic_cast<Krell::ModuleNetworkInfo *>(module.get())) {
          module->set_state(!module->get_state());
        }
      }
    }

    for (auto &module : modules)
      if (module->get_state())
        module->update();

    for (auto &module : modules)
      if (module->get_state())
        module->draw(*disp);

    disp->displayWindow();
    disp->setY(1);
  }
  return 1;
}

int main(void) {
  Krell::Ncurses nc;
  Krell::IDisplay *disp = &nc;
  Krell::IDisplay *tmp;

  std::vector<std::unique_ptr<Krell::IModule>> modules;
  modules.push_back(std::make_unique<Krell::ModuleBatteryInfo>());
  modules.push_back(std::make_unique<Krell::ModuleSystemInfo>());
  modules.push_back(std::make_unique<Krell::ModuleCpuInfo>());
  modules.push_back(std::make_unique<Krell::ModuleRamInfo>());
  modules.push_back(std::make_unique<Krell::ModuleNetworkInfo>());

  disp->init();
  while (mainLoop(disp, modules)) {
    disp->cleanup();
    tmp = disp;
    disp->init();
  }
  return 0;
}
