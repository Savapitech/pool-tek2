#include "SFML.hpp"

namespace Krell {

SFML::SFML() {
  _name = "SFML";
  this->_font.loadFromFile(FONT_PATH);
}

SFML::~SFML() { this->_window.close(); }

void SFML::init() {
  this->_window.create(sf::VideoMode().getDesktopMode(), "hello",
                       sf::Style::None);
  this->_window.setFramerateLimit(1);
  this->setState(true);
  return;
}

void SFML::displayWindow() { this->_window.display(); }

void SFML::refreshWindow() {
  while (this->_window.pollEvent(this->_event)) {
    if (this->_event.type == sf::Event::Closed) {
      this->setState(false);
    }
    if (this->_event.type == sf::Event::KeyPressed) {
      if (this->_event.key.code == sf::Keyboard::E) {
        this->setState(false);
        _keys.push_back('e');
      } else if (this->_event.key.code == sf::Keyboard::B) {
        _keys.push_back('b');
      } else if (this->_event.key.code == sf::Keyboard::S) {
        _keys.push_back('s');
      } else if (this->_event.key.code == sf::Keyboard::C) {
        _keys.push_back('c');
      } else if (this->_event.key.code == sf::Keyboard::R) {
        _keys.push_back('r');
      } else if (this->_event.key.code == sf::Keyboard::N) {
        _keys.push_back('n');
      }
    }
  }
  this->_window.clear();
}

void SFML::drawBox(int x, int y, int width, int height) {
  x *= X_RATIO;
  y *= Y_RATIO;
  width *= X_RATIO;
  height *= Y_RATIO;
  sf::RectangleShape rec(sf::Vector2f(width, height));
  rec.setPosition(sf::Vector2f(x, y));
  rec.setFillColor(sf::Color::Black);
  rec.setOutlineColor(sf::Color::White);
  rec.setOutlineThickness(2);
  this->_window.draw(rec);
}

void SFML::drawText(int x, int y, std::string text, bool header) {
  x *= X_RATIO;
  y *= Y_RATIO;
  sf::Text tex(text, this->_font, 20);
  tex.setPosition(sf::Vector2f(x, y));
  tex.setFillColor(sf::Color::White);
  tex.setOutlineColor(sf::Color::Black);
  this->_window.draw(tex);
}

void SFML::drawBar(int x, int y, int height, int width, uint8_t percentage,
                   std::string text, bool reverse_color) {
  x *= X_RATIO;
  width -= 2;
  width *= X_RATIO;
  y *= Y_RATIO;
  height *= Y_RATIO;
  sf::RectangleShape rec(sf::Vector2f(width, height));
  sf::Text tex(text, this->_font, 14);
  rec.setPosition(sf::Vector2f(x, y));
  rec.setFillColor(sf::Color::White);
  rec.setOutlineColor(sf::Color::Black);
  rec.setOutlineThickness(1);
  this->_window.draw(rec);
  double tmp = percentage;
  if (percentage > 75) {
    rec.setSize(sf::Vector2f(width * (tmp / 100), height));
    rec.setFillColor(sf::Color::Red);
    this->_window.draw(rec);
    tmp = 75;
  }
  if (percentage > 50) {
    rec.setSize(sf::Vector2f(width * (tmp / 100), height));
    rec.setFillColor(sf::Color::Yellow);
    this->_window.draw(rec);
    tmp = 50;
  }
  rec.setSize(sf::Vector2f(width * (tmp / 100), height));
  rec.setFillColor(sf::Color::Green);
  this->_window.draw(rec);
  sf::Vector2f vec = tex.getGlobalBounds().getSize();
  tex.setPosition(sf::Vector2f(x + (width / 2) - (vec.x / 2), y - vec.y * 1.5));
  tex.setFillColor(sf::Color::White);
  this->_window.draw(tex);
}

void SFML::drawGraph(int x, int y, int height, int width, int nbelem,
                     std::deque<uint8_t> &queue, std::string title) {
  int startx = x;
  int starty = y;
  x *= X_RATIO;
  y *= Y_RATIO;
  width *= X_RATIO;
  height *= Y_RATIO;
  int ind_width = width / CPU_QUEUE_SIZE;
  sf::RectangleShape rec(sf::Vector2f(ind_width * nbelem, height));
  rec.setPosition(sf::Vector2f(x, y));
  rec.setFillColor(sf::Color::Black);
  rec.setOutlineColor(sf::Color::White);
  rec.setOutlineThickness(2);
  this->_window.draw(rec);
  rec.setOutlineThickness(0);
  x += ind_width * (nbelem - 1);
  double elheight = 0;
  for (auto val : queue) {
    if (val > 75) {
      rec.setFillColor(sf::Color::Red);
      elheight = height * (double(val) / 100);
      rec.setSize(sf::Vector2f(ind_width, elheight));
      rec.setPosition(sf::Vector2f(x, y + (height - elheight)));
      this->_window.draw(rec);
      val = 75;
    }
    if (val > 50) {
      rec.setFillColor(sf::Color::Yellow);
      elheight = height * (double(val) / 100);
      rec.setSize(sf::Vector2f(ind_width, elheight));
      rec.setPosition(sf::Vector2f(x, y + (height - elheight)));
      this->_window.draw(rec);
      val = 50;
    }
    rec.setFillColor(sf::Color::Green);
    elheight = height * (double(val) / 100);
    rec.setSize(sf::Vector2f(ind_width, elheight));
    rec.setPosition(sf::Vector2f(x, y + (height - elheight)));
    this->_window.draw(rec);
    x -= ind_width;
  }
  this->drawText(startx + 1, starty + 1, title, false);
}

const sf::RenderWindow &SFML::getWindow() const { return this->_window; }

void SFML::cleanup() { this->_window.close(); }

} // namespace Krell
