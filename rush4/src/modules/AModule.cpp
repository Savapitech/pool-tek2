#include "AModule.hpp"
#include <ncurses.h>

namespace Krell {

std::string AModule::get_name() const { return _name; }

bool AModule::get_state() const { return _state; }

void AModule::set_state(bool state) { _state = state; }

} // namespace Krell
