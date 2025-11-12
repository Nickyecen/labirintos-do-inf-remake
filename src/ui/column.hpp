#pragma once

#include "ui-node.hpp"
#include <concepts>
#include <memory>
#include <vector>

class Column : public UINode {
protected:
  std::vector<std::unique_ptr<UINode>> _nodes;

public:
  Column();

  Column *add(std::unique_ptr<UINode> node);
  size_t getNumNodes() const { return _nodes.size(); }
  void remove(const int pos = -1);

  UINode *getNode(const int pos) const;
  void setNode(const int pos, std::unique_ptr<UINode> node);

  virtual void refresh() override;
  virtual void draw() override;
};
