#pragma once

#include <raylib.h>

class UINode {
protected:
  Vector2 _tl, _br;
  bool _dirty = true;

public:
  virtual ~UINode() = default;

  virtual void draw() = 0;

  virtual void refresh() = 0;

  bool dirty() { return _dirty; }
  void setDirty() { _dirty = true; }

  Vector2 getTL() const { return _tl; }
  void setTL(const Vector2 tl) {
    setDirty();
    _tl = tl;
  }

  Vector2 getBR() const { return _br; }
  void setBR(const Vector2 br) {
    setDirty();
    _br = br;
  }
};
