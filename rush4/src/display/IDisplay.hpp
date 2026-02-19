#pragma once

#include <cstdint>
#include <string>
#include <stdint.h>
#include <deque>
#include <vector>

#define CPU_QUEUE_SIZE 100
#define RAM_QUEUE_SIZE 100
#define BATTERY_QUEUE_SIZE 100

namespace Krell {

class IDisplay {
  public:
    virtual ~IDisplay() = default;
    virtual void init() = 0;
    virtual void displayWindow() = 0;
    virtual void refreshWindow() = 0;
    virtual void drawBox(int x, int y, int width, int height) = 0;
    virtual void drawText(int x, int y, std::string text, bool header = false) = 0;
    virtual void drawBar(int x, int y, int height, int width, uint8_t percentage, std::string text, bool reverse_color = false) = 0;
    virtual void drawGraph(int x, int y, int height, int width, int nbelem, std::deque<uint8_t> &queue, std::string title) = 0;
    virtual void cleanup() = 0;
    virtual bool getState() const = 0;
    virtual void setState(bool state) = 0;
    virtual std::vector<int> getKeys() = 0;
    virtual int getY() const = 0;
    virtual void setY(int y) = 0;
};

} // namespace Krell
