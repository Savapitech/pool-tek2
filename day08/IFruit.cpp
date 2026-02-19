#include "IFruit.hpp"

std::ostream &operator<<(std::ostream &os, const IFruit &rhs) {
  os <<"{ \"name\": \"" << rhs.getName() << "\", \"vitamins\": " << rhs.getVitamins() << ", \"peeled\": " << (rhs.isPeeled() ? "true" : "false") <<" }";
  return os;
}
