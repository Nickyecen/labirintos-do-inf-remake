#include "frame.hpp"
#include <raylib.h>

Frame::Frame(std::unique_ptr<UINode> content) : _content(std::move(content)) {
  const Vector2 br = {(float)GetScreenWidth(), (float)GetScreenHeight()};
  _tl = {0, 0};
  _br = br;

  _content->setTL({0, 0});
  _content->setBR(br);

  _content->refresh();
}

void Frame::draw() { _content->draw(); }
void Frame::refresh() {
  const Vector2 br = {(float)GetScreenWidth(), (float)GetScreenHeight()};
  if (!(_br.x == br.x && _br.y == br.y)) {
    _br = br;
    _content->setBR(br);
  }

  _content->refresh();
}
