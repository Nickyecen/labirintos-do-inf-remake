#ifndef MAIN_MENU_STATE_HEADER
#define MAIN_MENU_STATE_HEADER

#include "../../render/renderer.hpp"
#include "../../state-machines/interface_state.hpp"
#include "raylib.h"
#include <memory>

class MainMenuState : public InterfaceState {
public:
private:
  Color _backgroundColor = {0, 0, 0, 1};
  Texture2D _backgroundTexture;

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
