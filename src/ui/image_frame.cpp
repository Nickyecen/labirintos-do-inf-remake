#include "image_frame.hpp"
#include "ui-node.hpp"
#include <raylib.h>

// Draws image on screen
void ImageFrame::draw() {
  DrawTextureEx(_image, Vector2{(float)_xPos, (float)_yPos}, 0, _scaleScalar,
                WHITE);
}

void ImageFrame::refresh() {
  if (!dirty())
    return;

  int canvasWidth = (_br.x - _tl.x);
  int canvasHeight = (_br.y - _tl.y);

  switch (_scale) {
  case UINode::Scale::KEEP_PROPORTION_FILL: {
    float scaleW = (float)canvasWidth / _image.width;
    float scaleH = (float)canvasHeight / _image.height;
    _scaleScalar = scaleW > scaleH ? scaleW : scaleH;
    break;
  }
  case UINode::Scale::KEEP_PROPORTION_FIT: {
    float scaleW = (float)canvasWidth / _image.width;
    float scaleH = (float)canvasHeight / _image.height;
    _scaleScalar = scaleW < scaleH ? scaleW : scaleH;
    break;
  }
  default: {
    _scaleScalar = 1.0;
  }
  }

  int scaledWidth = _image.width * _scaleScalar;
  int scaledHeight = _image.height * _scaleScalar;

  switch (_position) {
  case UINode::Position::TOP_CENTER:
  case UINode::Position::CENTER:
  case UINode::Position::BOTTOM_CENTER:
    _xPos = canvasWidth / 2 - scaledWidth / 2;
    break;
  case UINode::Position::TOP_RIGHT:
  case UINode::Position::CENTER_RIGHT:
  case UINode::Position::BOTTOM_RIGHT:
    _xPos = canvasWidth - scaledWidth;
    break;
  default:
    _xPos = 0;
    break;
  }

  switch (_position) {
  case UINode::Position::CENTER_LEFT:
  case UINode::Position::CENTER:
  case UINode::Position::CENTER_RIGHT:
    _yPos = canvasHeight / 2 - scaledHeight / 2;
    break;
  case UINode::Position::BOTTOM_LEFT:
  case UINode::Position::BOTTOM_CENTER:
  case UINode::Position::BOTTOM_RIGHT:
    _yPos = canvasHeight - scaledHeight;
    break;
  default:
    _yPos = 0;
    break;
  }

  _dirty = false;
}
