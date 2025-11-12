#include "menus.hpp"

#include "../state-machines/interface_state.hpp"
#include "main-menu/main_menu.hpp"

bool Menus::isFinal() const { return false; }

void Menus::enter() {
  std::unique_ptr<InterfaceState> mainMenu = std::make_unique<MainMenuState>();
  _interfaceStateMachine = std::make_unique<StateMachine>(std::move(mainMenu));
  _interfaceStateMachine->run();
  _shouldStop = true;
}

std::unique_ptr<State> Menus::update() { return nullptr; }

void Menus::exit() {}
