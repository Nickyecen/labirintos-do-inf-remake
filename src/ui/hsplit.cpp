#include "hsplit.hpp"
#include "ui-node.hpp"
#include <raylib.h>

HSplit::HSplit(std::unique_ptr<UINode> top, std::unique_ptr<UINode> bottom,
               const float split)
    : _top(std::move(top)), _bottom(std::move(bottom)), _split(split) {
  refresh();
}

void HSplit::draw() {
  _top->draw();
  _bottom->draw();
}

void HSplit::refresh() {
  if (!_dirty) {
    _top->refresh();
    _bottom->refresh();
    return;
  }

  _dirty = false;

  float mid = _split * (getBR().y - getTL().y);
  Vector2 midLeft = (Vector2){getTL().x, mid};
  Vector2 midRight = (Vector2){getBR().x, mid};

  _top->setTL(getTL());
  _top->setBR(midRight);
  _bottom->setTL(midLeft);
  _bottom->setBR(getBR());

  _top->refresh();
  _bottom->refresh();
}
