#include "menus.hpp"

#include "../state-machines/interface_state.hpp"
#include "../state-machines/state_machine.hpp"
#include "main-menu/main_menu.hpp"

bool Menus::isFinal() const { return true; }

// Starts interface SM that controls menus
void Menus::enter() {
  std::unique_ptr<InterfaceState> mainMenu = std::make_unique<MainMenuState>();
  std::unique_ptr<StateMachine> interfaceStateMachine =
      std::make_unique<StateMachine>(std::move(mainMenu));
  interfaceStateMachine->run();
  _shouldStop = true;
}

// Doesn't need to update, will always stop the SM on entering
std::unique_ptr<State> Menus::update() { return nullptr; }

// Doesn't have any activities on exit
void Menus::exit() {}
