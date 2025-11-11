#include "../render/renderer.hpp"
#include "ui-node.hpp"
#include <raylib.h>
#include <string>

class Label : public UINode {
protected:
  std::string _text;
  unsigned int _size;
  Color _color;
  RenderPosition _position = RenderPosition::TOP_LEFT;
  int _centerX, _centerY;

public:
  Label(std::string text, unsigned int size, Color color)
      : _text(text), _size(size), _color(color) {
    int canvasCenterX = _tl.x + (_br.x - _tl.x) / 2;
    int canvasCenterY = _tl.y + (_br.y - _tl.y) / 2;
    _centerX = canvasCenterX - (MeasureText(_text.c_str(), _size)) / 2;
    _centerY = canvasCenterY - _size / 2;
  }

  Label(std::string text, unsigned int size, Color color,
        RenderPosition position)
      : _text(text), _size(size), _color(color), _position(position) {
    int canvasCenterX = _tl.x + (_br.x - _tl.x) / 2;
    int canvasCenterY = _tl.y + (_br.y - _tl.y) / 2;
    _centerX = canvasCenterX - (MeasureText(_text.c_str(), _size)) / 2;
    _centerY = canvasCenterY - _size / 2;
  }

  virtual void draw() override;
  virtual void refresh() override;

  std::string getText() const { return _text; }
  unsigned int getFontSize() const { return _size; }
  Color getColor() const { return _color; }
  RenderPosition getRenderPosition() const { return _position; }

  void setText(const std::string text) {
    setDirty();
    _text = text;
  }
  void setFontSize(const unsigned int size) {
    setDirty();
    _size = size;
  }
  void setColor(const Color color) { _color = color; }
  void setRenderPosition(const RenderPosition position) {
    _position = position;
  }
};
