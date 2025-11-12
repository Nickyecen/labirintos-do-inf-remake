#ifndef MAIN_MENU_STATE_HEADER
#define MAIN_MENU_STATE_HEADER

#define TITLE_SIZE 64
#define BUTTON_SIZE 24

#include "../../state-machines/interface_state.hpp"
#include "../../ui/ui-node.hpp"
#include "raylib.h"
#include <memory>

class MainMenuState : public InterfaceState {
public:
private:
  Color _backgroundColor = {0, 0, 0, 255};
  Texture2D _backgroundTexture;

  std::unique_ptr<UINode> _content;
  bool _shouldStop = false;

public:
  MainMenuState();
  ~MainMenuState();

  bool shouldStop() const override;
  bool shouldDraw() const override;
  bool isFinal() const override;

  virtual void enter() override;
  virtual std::unique_ptr<State> update() override;
  virtual void draw() const override;
  virtual void exit() override;

private:
};

#endif
