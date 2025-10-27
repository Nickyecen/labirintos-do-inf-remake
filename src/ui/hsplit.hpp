#pragma once

#include "ui-node.hpp"
#include <memory>
#include <raylib.h>

class HSplit : public UINode {
protected:
  std::unique_ptr<UINode> _top, _bottom;
  float _split;

public:
  HSplit(std::unique_ptr<UINode> top, std::unique_ptr<UINode> bottom,
         const float split);

  virtual void refresh() override;

  float getSplit() const { return _split; }
  void setSplit(const float split) {
    setDirty();

    if (split < 0 || split > 1) {
      TraceLog(LOG_ERROR, "Tried setting vsplit out of range (0.0 - 1.0)");
      return;
    }

    _split = split;
  }
};
