#pragma once

#include "../ADisplay.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <string>

#define FONT_PATH "src/assets/Radiant Regular/Radiant.ttf"
#define X_RATIO 8
#define Y_RATIO 9

namespace Krell {

class SFML : public ADisplay {
public:
  SFML();
  ~SFML();
  virtual void init() override;
  virtual void displayWindow() override;
  virtual void refreshWindow() override;
  virtual void drawBox(int x, int y, int width, int height) override;
  virtual void drawText(int x, int y, std::string text,
                        bool header = false) override;
  virtual void drawBar(int x, int y, int height, int width, uint8_t percentage,
                       std::string text, bool reverse_color = false) override;
  virtual void drawGraph(int x, int y, int height, int width, int nbelem,
                         std::deque<uint8_t> &queue,
                         std::string title) override;
  virtual void cleanup() override;

  const sf::RenderWindow &getWindow() const;

private:
  sf::RenderWindow _window;
  sf::Font _font;
  sf::Event _event;
};

} // namespace Krell
