#pragma once

#include "IModule.hpp"

namespace Krell {

class AModule : public IModule {
public:
  virtual ~AModule() = default;
  virtual std::string get_name() const override;
  virtual bool get_state() const override;
  virtual void set_state(bool state) override;

protected:
  std::string _name;
  bool _state = true;
};

} // namespace Krell
