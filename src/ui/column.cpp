#include "column.hpp"
#include "ui-node.hpp"
#include <cstddef>

Column::Column() {}

Column *Column::add(std::unique_ptr<UINode> node) {
  setDirty();

  _nodes.push_back(std::move(node));

  return this;
}

void Column::remove(const int pos) {
  setDirty();

  auto actualPos = pos < 0 ? _nodes.end() + pos : _nodes.begin() + pos;
  _nodes.erase(actualPos);
}

UINode *Column::getNode(const int pos) const {
  return _nodes.at(pos < 0 ? _nodes.size() + pos : pos).get();
}

void Column::setNode(const int pos, std::unique_ptr<UINode> node) {
  setDirty();

  auto actualPos = pos < 0 ? _nodes.end() + pos : _nodes.begin() + pos;
  _nodes.erase(actualPos);
  _nodes.insert(actualPos, std::move(node));
}

void Column::refresh() {
  if (!_dirty) {
    for (auto &node : _nodes) {
      node->refresh();
    }
    return;
  }

  _dirty = false;

  int numNodes = getNumNodes();
  float height = (_br.y - _tl.y) / (float)numNodes;
  for (int i = 0; i < numNodes; i++) {
    UINode *node = _nodes[i].get();
    node->setTL({_tl.x, _tl.y + i * height});
    node->setBR({_br.x, _tl.y + (i + 1) * height});
    node->refresh();
  }
}

void Column::draw() {
  for (auto &node : _nodes) {
    node->draw();
  }
}
