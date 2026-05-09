#include "ui-node.hpp"
#include <raylib.h>
#include <string>

// A UINode that contains text
class Label : public UINode {
protected:
  std::string _text;                                       // Drawn text
  unsigned int _size;                                      // Font size
  Color _color;                                            // Text color
  UINode::Position _position = UINode::Position::TOP_LEFT; // Text position
  int _centerX, _centerY; // Text center for positioning

public:
  // Constructor
  Label(std::string const text, unsigned int const size, Color const color,
        UINode::Position const position = UINode::Position::TOP_LEFT)
      : _text(text), _size(size), _color(color), _position(position) {
    setDirty();
    refresh();
  }

  virtual void draw() override;
  virtual void refresh() override;

  // Getters and setters
  std::string getText() const { return _text; }
  unsigned int getFontSize() const { return _size; }
  Color getColor() const { return _color; }
  UINode::Position getPosition() const { return _position; }

  void setText(const std::string text) {
    setDirty();
    _text = text;
  }
  void setFontSize(const unsigned int size) {
    setDirty();
    _size = size;
  }
  void setColor(const Color color) { _color = color; }
  void setPosition(const UINode::Position position) { _position = position; }
};
