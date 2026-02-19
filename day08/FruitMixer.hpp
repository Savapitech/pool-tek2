#pragma once

#include "IFruit.hpp"
#include "FruitBox.hpp"
#include <iostream>

class IFruitMixer
{
public:
    class IBlade
    {
    public:
        virtual ~IBlade() = default;

        virtual unsigned int operator()(const IFruit& fruit) const = 0;
    };

    virtual ~IFruitMixer() = default;

    virtual unsigned int mixFruits(FruitBox& box) const = 0;
    virtual void setBlade(IBlade* blade) = 0;
};

class FruitMixer : public IFruitMixer {
  private:
    IBlade *_blade;

  public:
    FruitMixer();
    ~FruitMixer() = default;

    unsigned int mixFruits(FruitBox &box) const override;
    void setBlade(IBlade *blade) override;
};
