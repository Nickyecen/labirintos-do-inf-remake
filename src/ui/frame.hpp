#pragma once

#include "ui-node.hpp"
#include <memory>

// A window sized UINode that holds another UINode
class Frame : public UINode {
private:
  std::unique_ptr<UINode> _content;

public:
  Frame(std::unique_ptr<UINode> _content);

  virtual void draw() override;
  virtual void refresh() override;
};
