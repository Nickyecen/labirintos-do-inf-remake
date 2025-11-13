#pragma once

#include <map>
#include <memory>
#include <string>

class GNode {
private:
  GNode *_parent;
  std::map<std::string, std::unique_ptr<GNode>> _children;
  std::string _name;

public:
  GNode(std::string const name);
  ~GNode() = default;

  virtual void update();
  virtual void draw2D() const;
  virtual void draw3D() const;

  std::string getName() const;
  void setName(std::string const name);

  GNode *getParent() const;
  GNode *getChild(std::string const name) const;
  bool hasChild(std::string const name) const;

  void updateChildren();
  void addChild(std::unique_ptr<GNode> child);
  void removeChild(std::string const name);
};
