#pragma once

#include "../display/IDisplay.hpp"
#include "AModule.hpp"
#include <deque>

namespace Krell {

class ModuleCpuInfo : public AModule {
public:
  ModuleCpuInfo() = default;
  ~ModuleCpuInfo() = default;
  virtual void draw(IDisplay &display) override;
  virtual void update() override;

private:
  std::deque<uint8_t> _queue;
};

} // namespace Krell
