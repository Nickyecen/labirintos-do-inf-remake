#pragma once

#include "ui-node.hpp"
#include <memory>
#include <vector>

// A UINode that contains text
class Overlay : public UINode {
protected:
  std::vector<std::unique_ptr<UINode>> _nodes;

public:
  template <typename... Args> Overlay(Args &&...args) {
    (this->add(std::forward<Args>(args)), ...);
  }

  // Adds a UINode to the overlay
  Overlay *add(std::unique_ptr<UINode> node);
  size_t getNumNodes() const { return _nodes.size(); }

  // Removes a node from the overlay, default last
  void remove(const int pos = -1);

  // Gets a node from the overlay
  UINode *getNode(const int pos) const;

  // Changes a node from the overlay
  void setNode(const int pos, std::unique_ptr<UINode> node);

  virtual void refresh() override;
  virtual void draw() override;
};
