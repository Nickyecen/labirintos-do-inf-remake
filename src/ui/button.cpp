#include "button.hpp"
#include <iostream>
#include <raylib.h>

void Button::draw() { _resource->draw(); }

void Button::refresh() {
  if (dirty()) {
    _dirty = false;
    _resource->setTL(_tl);
    _resource->setBR(_br);
  }

  Vector2 pos = GetMousePosition();
  const bool over =
      _tl.x <= pos.x && _br.x >= pos.x && _tl.y <= pos.y && _br.y >= pos.y;

  if (!over) {
    if (onNotHover)
      onNotHover((const int)pos.x, (const int)pos.y);
    _resource->refresh();
    return;
  }

  if (onHover)
    onHover((const int)pos.x, (const int)pos.y);

  if (onLeftClick && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    onLeftClick((const int)pos.x, (const int)pos.y);
  if (onLeftDown && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    onLeftDown((const int)pos.x, (const int)pos.y);
  if (onLeftUp && IsMouseButtonUp(MOUSE_LEFT_BUTTON))
    onLeftUp((const int)pos.x, (const int)pos.y);
  if (onLeftRelease && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    onLeftRelease((const int)pos.x, (const int)pos.y);

  if (onRightClick && IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    onRightClick((const int)pos.x, (const int)pos.y);
  if (onRightDown && IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
    onRightDown((const int)pos.x, (const int)pos.y);
  if (onRightUp && IsMouseButtonUp(MOUSE_RIGHT_BUTTON))
    onRightUp((const int)pos.x, (const int)pos.y);
  if (onRightRelease && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON))
    onRightRelease((const int)pos.x, (const int)pos.y);

  _resource->refresh();
}
