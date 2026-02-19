#include "../ADisplay.hpp"
#include <ncurses.h>

namespace Krell {

class Ncurses : public ADisplay {
public:
  Ncurses();
  virtual ~Ncurses();
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
                         std::string title) override {};
  virtual void cleanup() override;

private:
  WINDOW *_window;
  int _ch;
};

} // namespace Krell
