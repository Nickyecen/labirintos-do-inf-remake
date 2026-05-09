#include "overlay.hpp"
#include "ui-node.hpp"

Overlay *Overlay::add(std::unique_ptr<UINode> node) {
  setDirty();

  // Adds a node to the end of the overlay
  _nodes.push_back(std::move(node));

  return this;
}

void Overlay::remove(const int pos) {
  setDirty();

  // Removes pos node from the overlay
  auto actualPos = pos < 0 ? _nodes.end() + pos : _nodes.begin() + pos;
  _nodes.erase(actualPos);
}

UINode *Overlay::getNode(const int pos) const {
  // Gets node at pos
  return _nodes.at(pos < 0 ? _nodes.size() + pos : pos).get();
}

void Overlay::setNode(const int pos, std::unique_ptr<UINode> node) {
  setDirty();

  // Changes node at pos
  auto actualPos = pos < 0 ? _nodes.end() + pos : _nodes.begin() + pos;
  _nodes.erase(actualPos);
  _nodes.insert(actualPos, std::move(node));
}

void Overlay::refresh() {
  // Refreshes all nodes in the overlay
  if (!_dirty) {
    for (auto &node : _nodes) {
      node->refresh();
    }
    return;
  }

  _dirty = false;

  int numNodes = getNumNodes();
  for (int i = 0; i < numNodes; i++) {
    UINode *node = _nodes[i].get();
    node->setTL({_tl.x, _tl.y});
    node->setBR({_br.x, _br.y});
    node->refresh();
  }
}

void Overlay::draw() {
  for (auto &node : _nodes) {
    node->draw();
  }
}
