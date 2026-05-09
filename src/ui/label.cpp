#include "label.hpp"
#include <raylib.h>

// Draws text on screen
void Label::draw() {
  int posX, posY;
  int const size = MeasureText(_text.c_str(), _size);

  // Selects position to be draw
  switch (_position) {
  case RenderPosition::TOP_LEFT:
    posX = _tl.x;
    posY = _tl.y;
    break;
  case RenderPosition::TOP_CENTER:
    posX = _centerX;
    posY = _tl.y;
    break;
  case RenderPosition::TOP_RIGHT:
    posX = _br.x - size;
    posY = _tl.y;
    break;
  case RenderPosition::CENTER_LEFT:
    posX = _tl.x;
    posY = _centerY;
    break;
  case RenderPosition::CENTER:
    posX = _centerX;
    posY = _centerY;
    break;
  case RenderPosition::CENTER_RIGHT:
    posX = _br.x - size;
    posY = _centerY;
    break;
  case RenderPosition::BOTTOM_LEFT:
    posX = _tl.x;
    posY = _br.y - _size;
    break;
  case RenderPosition::BOTTOM_CENTER:
    posX = _centerX;
    posY = _br.y - _size;
    break;
  case RenderPosition::BOTTOM_RIGHT:
    posX = _br.x - size;
    posY = _br.y - _size;
    break;
  default:
    posX = _tl.x;
    posY = _tl.y;
    TraceLog(LOG_WARNING, "Label set posX and posY to default values");
  }

  // Draws text
  DrawText(_text.c_str(), posX, posY, _size, _color);
}

void Label::refresh() {
  if (!dirty())
    return;

  int canvasCenterX = _tl.x + (_br.x - _tl.x) / 2;
  int canvasCenterY = _tl.y + (_br.y - _tl.y) / 2;
  _centerX = canvasCenterX - (MeasureText(_text.c_str(), _size)) / 2;
  _centerY = canvasCenterY - _size / 2;

  _dirty = false;
}
