#include "label.hpp"
#include <raylib.h>

void Label::draw() {
  switch (_position) {
  case RenderPosition::TOP_LEFT:
    DrawText(_text.c_str(), _tl.x, _tl.y, _size, _color);
    break;
  case RenderPosition::TOP_CENTER:
    DrawText(_text.c_str(), _centerX, _tl.y, _size, _color);
    break;
  case RenderPosition::TOP_RIGHT: {
    int size = MeasureText(_text.c_str(), _size);
    DrawText(_text.c_str(), _br.x - size, _tl.y, _size, _color);
    break;
  }
  case RenderPosition::CENTER_LEFT:
    DrawText(_text.c_str(), _tl.x, _centerY, _size, _color);
    break;
  case RenderPosition::CENTER:
    DrawText(_text.c_str(), _centerX, _centerY, _size, _color);
    break;
  case RenderPosition::CENTER_RIGHT: {
    int size = MeasureText(_text.c_str(), _size);
    DrawText(_text.c_str(), _br.x - size, _centerY, _size, _color);
    break;
  }
  case RenderPosition::BOTTOM_LEFT:
    DrawText(_text.c_str(), _tl.x, _br.y - _size, _size, _color);
    break;
  case RenderPosition::BOTTOM_CENTER:
    DrawText(_text.c_str(), _centerX, _br.y - _size, _size, _color);
    break;
  case RenderPosition::BOTTOM_RIGHT: {
    int size = MeasureText(_text.c_str(), _size);
    DrawText(_text.c_str(), _br.x - size, _br.y - _size, _size, _color);
    break;
  }
  }
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
