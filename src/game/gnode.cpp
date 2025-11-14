#include "gnode.hpp"
#include <cstdlib>
#include <raylib.h>
#include <sstream>

GNode::GNode(std::string const name) {
  if (!this->setName(name)) {
    TraceLog(LOG_FATAL, "Unable to create node with name \"%s\"", name.c_str());
  }
}

void GNode::update() {}
void GNode::draw2D() const {}
void GNode::draw3D() const {}

std::string GNode::getName() const { return _name; }
std::string GNode::getFullName() const {
  std::stringstream ss;

  if (!_parent) {
    ss << '/' << _name;
  } else {
    ss << _parent->getFullName() << "/" << getName();
  }

  return ss.str();
}
bool GNode::setName(std::string const name) {
  for (char c : name) {
    if (c == '/') {
      TraceLog(LOG_ERROR, "Tried to rename node \"%s\" to invalid name \"%s\"",
               this->getFullName().c_str(), name.c_str());
      return false;
    }
  }

  if (_parent && _parent->hasChild(name)) {
    TraceLog(LOG_ERROR,
             "Tried to rename node \"%s\" to already existing node \"%s\" in "
             "tree \"%s\"",
             this->getName().c_str(), name.c_str(),
             _parent->getFullName().c_str());
    return false;
  }

  _name = name;
  return true;
}

GNode *GNode::getParent() const { return _parent; }
GNode *GNode::getChild(std::string const name) const {
  auto it = _childrenMap.find(name);
  return it == _childrenMap.end() ? nullptr : it->second;
}
std::map<std::string, GNode *> GNode::getChildren() const {
  return _childrenMap;
}
bool GNode::hasChild(std::string const name) const {
  return _childrenMap.find(name) != _childrenMap.end();
}

void GNode::addChild(std::unique_ptr<GNode> child) {
  const std::string name = child->getName();
  if (this->hasChild(name)) {
    TraceLog(LOG_ERROR,
             "Tried to insert already existing node \"%s\" to tree \"%s\"",
             name.c_str(), this->getName().c_str());
  }

  _childrenMap.insert({name, child.get()});
  _childrenList.push_back(std::move(child));
}
void GNode::removeChild(std::string const name) {
  auto it = _childrenMap.find(name);
  if (it == _childrenMap.end())
    return;
  _childrenMap.erase(it);
}
