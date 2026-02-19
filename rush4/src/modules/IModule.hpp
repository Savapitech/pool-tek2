#pragma once

#include "../display/IDisplay.hpp"

namespace Krell {

class IModule {
public:
  virtual ~IModule() = default;
  virtual std::string get_name() const = 0;
  virtual bool get_state() const = 0;
  virtual void set_state(bool state) = 0;
  virtual void draw(IDisplay &display) = 0;
  virtual void update() = 0;
};

} // namespace Krell
