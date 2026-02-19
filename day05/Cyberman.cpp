#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

#include "Cyberman.hpp"
#include "Human.hpp"

char to_leet(char c)
{
  static const std::unordered_map<char, char> leet = {
    {'a', '4'},
    {'b', '8'},
    {'e', '3'},
    {'g', '6'},
    {'i', '1'},
    {'l', '1'},
    {'o', '0'},
    {'r', '2'},
    {'s', '5'},
    {'t', '7'},
    {'y', '7'},
    {' ', '_'}
  };

  char lower = std::tolower(static_cast<unsigned char>(c));
  auto it = leet.find(lower);
  return it != leet.end() ? it->second : c;
}

std::string leet_convert(const std::string &input)
{
  std::string out;

  for (char c : input)
    out += to_leet(c);
  return out;
}

Mondas::Cyberman::Cyberman(Mondas::Human &human) : _human(human)
{
  this->_name = leet_convert(this->_human.getName());
  std::cout << this->_name << ": Unit activated." << std::endl;
}

Mondas::Cyberman::~Cyberman() {
  std::cout << this->_name << ": Unit deactivated." << std::endl;
}

Mondas::Human &Mondas::Cyberman::getHuman() {
  return this->_human;
}

const Mondas::Human &Mondas::Cyberman::getHuman() const {
  return this->_human;
}

Mondas::Cyberman::Inhibitor::Inhibitor() {
  this->_activated = false;
}

void Mondas::Cyberman::Inhibitor::set(bool value)
{
  this->_activated = value;
}

bool Mondas::Cyberman::Inhibitor::get() {
  return this->_activated;
}

void Mondas::Cyberman::think() const {
  if (this->_human.getInhibitor() != nullptr && this->_human.getInhibitor()->get())
      std::cout << this->_name << ": Computation in progress." << std::endl;
  else
      std::cout << this->_name << ": Pain, pain, pain..." << std::endl;
}

unsigned int Mondas::Cyberman::getIq() const {
  if (this->_human.getInhibitor() != nullptr && this->_human.getInhibitor()->get())
      return this->_human.getIq();
  return 0;
}


std::string Mondas::Cyberman::getName() const {
  return this->_name;
}
