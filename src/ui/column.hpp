#pragma once

#include "ui-node.hpp"
#include <memory>
#include <vector>

// UINode that holds a list of UINodes on top of each other in a column
class Column : public UINode {
protected:
  std::vector<std::unique_ptr<UINode>> _nodes;

public:
  Column();

  // Adds a UINode to the column
  Column *add(std::unique_ptr<UINode> node);
  size_t getNumNodes() const { return _nodes.size(); }

  // Removes a node from the column, default last
  void remove(const int pos = -1);

  // Gets a node from the column
  UINode *getNode(const int pos) const;
  // Changes a node from the column
  void setNode(const int pos, std::unique_ptr<UINode> node);

  virtual void refresh() override;
  virtual void draw() override;
};
