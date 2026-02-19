#pragma once

#include "../Metrics.hpp"
#include "AModule.hpp"

namespace Krell {

class ModuleNetworkInfo : public AModule {
public:
  ModuleNetworkInfo() = default;
  ~ModuleNetworkInfo() = default;
  virtual void draw(IDisplay &display) override;
  virtual void update() override;
};

} // namespace Krell
