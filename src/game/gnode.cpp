#include "gnode.hpp"
#include <raylib.h>

GNode::GNode(std::string const name) : _name(name) {}

void GNode::update() {}
void GNode::draw2D() const {}
void GNode::draw3D() const {}

GNode *GNode::getParent() const { return _parent; }
GNode *GNode::getChild(std::string const name) const {
  auto it = _children.find(name);
  return it == _children.end() ? nullptr : it->second.get();
}
bool GNode::hasChild(std::string const name) const {
  return _children.find(name) != _children.end();
}

void GNode::updateChildren() {
  for (auto &child : _children) {
    child.second->update();
  }
}
void GNode::addChild(std::unique_ptr<GNode> child) {
  const std::string name = child->getName();
  if (this->hasChild(name)) {
    TraceLog(LOG_ERROR,
             "Tried to insert already existing node \"%s\" to tree \"%s\"",
             name.c_str(), this->getName().c_str());
  }

  _children.insert({name, std::move(child)});
}
void GNode::removeChild(std::string const name) {
  auto it = _children.find(name);
  if (it == _children.end())
    return;
  _children.erase(it);
}
