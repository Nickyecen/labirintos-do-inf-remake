#pragma once

#include "ui-node.hpp"
#include <functional>
#include <memory>

// A UINode that behaves like a clickable button
class Button : public UINode {
private:
  std::unique_ptr<UINode> _resource;
  bool _wasHovering = false;

public:
  Button(std::unique_ptr<UINode> resource) : _resource(std::move(resource)) {}

  using mouseFunc = std::function<void(const int mouseX, const int mouseY)>;

  mouseFunc onHover;       // Just hovered over button
  mouseFunc onNotHover;    // Just stopped hovering
  mouseFunc onHovering;    // On hovering over button
  mouseFunc onNotHovering; // On not hovering button

  mouseFunc onLeftClick;   // Just left clicked button
  mouseFunc onLeftDown;    // On holding down left click
  mouseFunc onLeftUp;      // On not holding down left click
  mouseFunc onLeftRelease; // Just released left click

  mouseFunc onRightClick;   // Just right clicked button
  mouseFunc onRightDown;    // On holding down right click
  mouseFunc onRightUp;      // On not holding down right click
  mouseFunc onRightRelease; // Just released right click

  virtual void draw() override;
  virtual void refresh() override;
};
