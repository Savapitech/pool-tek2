#include "Orange.hpp"

class BloodOrange : public Orange{
  public:
    BloodOrange();
    ~BloodOrange() = default;
    IFruit *clone() const override;
};
