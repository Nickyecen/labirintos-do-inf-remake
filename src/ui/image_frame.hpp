#pragma once

#include "ui-node.hpp"
#include <raylib.h>
#include <string>

class ImageFrame : public UINode {
protected:
  std::string _imagePath;
  Texture2D _image;
  UINode::Position _position = UINode::Position::TOP_LEFT;   // Image position
  UINode::Scale _scale = UINode::Scale::KEEP_PROPORTION_FIT; // Image scale
  float _scaleScalar = 1.0; // Image scale float
  int _xPos, _yPos;         // (x, y) render position

public:
  // Constructor
  ImageFrame(std::string const imagePath,
             UINode::Position const position = UINode::Position::TOP_LEFT,
             UINode::Scale const scale = UINode::Scale::KEEP_PROPORTION_FIT)
      : _imagePath(imagePath), _position(position), _scale(scale) {
    _image = LoadTexture(imagePath.c_str());
    setDirty();
    refresh();
  }

  virtual void draw() override;
  virtual void refresh() override;

  // Getters and setters
  Texture2D getTexture() const { return _image; }
  std::string getImagePath() const { return _imagePath; }
  UINode::Position getPosition() const { return _position; }
  UINode::Scale getScale() const { return _scale; }

  void setImage(const std::string imagePath) {
    _imagePath = imagePath;
    _image = LoadTexture(imagePath.c_str());
  }
  void setPosition(const UINode::Position position) { _position = position; }
  void setScale(const UINode::Scale scale) { _scale = scale; }
};
