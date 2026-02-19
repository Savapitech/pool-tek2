#pragma once

#include "IFruit.hpp"

class AFruit : public IFruit {
  protected:
    bool _ispeeled;
    unsigned int _vitamins;
    std::string _name;
    AFruit(std::string name, unsigned int vitamins, bool ispeeled);

  public:
    virtual ~AFruit() = default;
    unsigned int getVitamins() const override;
    std::string getName() const override;
    bool isPeeled() const override;
    void peel() override;
};
