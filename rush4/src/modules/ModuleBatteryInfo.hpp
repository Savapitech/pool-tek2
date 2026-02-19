#pragma once

#include "../display/IDisplay.hpp"
#include "AModule.hpp"

namespace Krell {

class ModuleBatteryInfo : public AModule {
public:
  ModuleBatteryInfo() = default;
  ~ModuleBatteryInfo() = default;
  virtual void draw(IDisplay &display) override;
  virtual void update() override;

private:
  std::deque<uint8_t> _queue;
};

} // namespace Krell
