#pragma once

#include "IDisplay.hpp"
#include <string>
#include <vector>

namespace Krell {

class ADisplay : public IDisplay {
  int _y = 1;

  protected:
    std::string _name;
    bool _state = true;
    std::vector<int> _keys;

  public:
    virtual ~ADisplay() = default;
    
    virtual std::string getName() const {
      return _name;
    };
    
    virtual bool getState() const override {
      return _state;
    };
    
    virtual void setState(bool state) override {
      this->_state = state;
    };
    
    virtual std::vector<int> getKeys() override {
      std::vector<int> k = _keys;
      _keys.clear();
      return k;
    }

    virtual int getY() const override {
      return _y;
    }

    virtual void setY(int y) override {
      _y = y;
    }
};

} // namespace Krell
