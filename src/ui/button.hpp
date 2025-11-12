#pragma once

#include "ui-node.hpp"
#include <functional>
#include <memory>

class Button : public UINode {
private:
  std::unique_ptr<UINode> _resource;

public:
  Button(std::unique_ptr<UINode> resource) : _resource(std::move(resource)) {}

  using mouseFunc = std::function<void(const int mouseX, const int mouseY)>;

  mouseFunc onHover;
  mouseFunc onNotHover;

  mouseFunc onLeftClick;
  mouseFunc onLeftDown;
  mouseFunc onLeftUp;
  mouseFunc onLeftRelease;

  mouseFunc onRightClick;
  mouseFunc onRightDown;
  mouseFunc onRightUp;
  mouseFunc onRightRelease;

  virtual void draw() override;
  virtual void refresh() override;
};
