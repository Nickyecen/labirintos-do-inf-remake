#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

class GNode {
private:
  GNode *_parent = nullptr;
  std::vector<std::unique_ptr<GNode>> _childrenList;
  std::map<std::string, GNode *> _childrenMap;
  std::string _name;

protected:
  virtual void update();
  virtual void draw2D() const;
  virtual void draw3D() const;

public:
  GNode(std::string const name);
  ~GNode() = default;

  std::string getName() const;
  std::string getFullName() const;
  bool setName(std::string const name);

  GNode *getParent() const;
  GNode *getChild(std::string const name) const;
  std::map<std::string, GNode *> getChildren() const;
  bool hasChild(std::string const name) const;

  void addChild(std::unique_ptr<GNode> child);
  void removeChild(std::string const name);
};
