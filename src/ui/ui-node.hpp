#pragma once

#include <raylib.h>

// A Node that holds information to be drawn in a UI
class UINode {
public:
  enum class Position {
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    CENTER_LEFT,
    CENTER,
    CENTER_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT
  };

  enum class Scale {
    KEEP,
    KEEP_PROPORTION_FILL,
    KEEP_PROPORTION_FIT,
  };

protected:
  Vector2 _tl, _br;   // Top Left and Bottom Right
  bool _dirty = true; // If needs to be redrawn

public:
  virtual ~UINode() = default;

  // Draws UINode
  virtual void draw() = 0;

  // Recalculates info if dirty
  virtual void refresh() = 0;

  // Sets dirty if needs recalculation
  bool dirty() { return _dirty; }
  void setDirty() { _dirty = true; }

  // Getters and setters
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
