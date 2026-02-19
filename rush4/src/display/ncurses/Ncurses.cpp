#include <algorithm>
#include <ncurses.h>
#include <unistd.h>

#include "Ncurses.hpp"

namespace Krell {

Ncurses::Ncurses() { _name = "Ncurses"; }

Ncurses::~Ncurses() { endwin(); }

void Ncurses::init() {
  _window = initscr();
  start_color();
  curs_set(0);
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  cbreak();
  noecho();
  this->setState(true);
}

void Ncurses::drawBox(int x, int y, int width, int heigth) {
  heigth /= 2;
  y /= 2;

  mvhline(y, x + 1, ACS_HLINE, width - 1);
  mvvline(y + 1, x, ACS_VLINE, heigth - 1);
  mvvline(y + 1, x + width, ACS_VLINE, heigth - 1);
  mvhline(y + heigth, x + 1, ACS_HLINE, width - 1);
  mvaddch(y + heigth, x, ACS_LLCORNER);
  mvaddch(y + heigth, x + width, ACS_LRCORNER);
  mvaddch(y, x, ACS_ULCORNER);
  mvaddch(y, x + width, ACS_URCORNER);
}

void Ncurses::drawText(int x, int y, std::string text, bool header) {
  y /= 2;
  if (header) {
    attron(COLOR_PAIR(2));
  } else {
    attron(COLOR_PAIR(1));
  }
  mvprintw(y, x, " %s ", text.c_str());
  attroff(COLOR_PAIR(1));
  attroff(COLOR_PAIR(2));
}

void Ncurses::drawBar(int x, int y, int height, int width, uint8_t percentage,
                      std::string text, bool reverse_color) {
  percentage = std::clamp<uint8_t>(percentage, 0, 100);

  y /= 2;
  std::string content = " " + std::to_string(percentage) + "% " + text + " ";

  int barWidth = width - 3;
  int filled = barWidth * percentage / 100;

  for (int row = 0; row < height; ++row) {
    move(y + row, x);
    addch('[');

    for (int i = 0; i < barWidth; ++i) {
      bool isFilled = i < filled;

      if (i < barWidth / 2)
        attron(COLOR_PAIR(reverse_color ? 2 : 3));
      else if (i > barWidth / 2 && i <= barWidth / 4 * 3)
        attron(COLOR_PAIR(reverse_color ? 3 : 4));
      else if (i > barWidth / 4 * 3)
        attron(COLOR_PAIR(reverse_color ? 3 : 2));
      else
        attron(COLOR_PAIR(1));

      if (row == height / 2 &&
          i >= (barWidth - static_cast<int>(content.size())) / 2 &&
          i < (barWidth - static_cast<int>(content.size())) / 2 +
                  static_cast<int>(content.size())) {

        attron(COLOR_PAIR(1));
        int textIndex = i - (barWidth - content.size()) / 2;
        addch(content[textIndex]);
      } else
        addch(isFilled ? '|' : '.');

      attroff(COLOR_PAIR(1));
      attroff(COLOR_PAIR(2));
      attroff(COLOR_PAIR(3));
      attroff(COLOR_PAIR(4));
    }
    addch(']');
  }
}

void Ncurses::displayWindow() {
  timeout(1000);
  _ch = getch();
  if (_ch != ERR) {
    _keys.push_back(_ch);
    if (_ch == 'e')
      this->setState(false);
  }
}

void Ncurses::refreshWindow() {
  clear();
  refresh();
}

void Ncurses::cleanup() { endwin(); }

} // namespace Krell
