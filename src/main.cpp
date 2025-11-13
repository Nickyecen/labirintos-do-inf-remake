#include "menus/menus.hpp"
#include "state-machines/state_machine.hpp"
#include <raylib.h>

int main() {
  SetTraceLogLevel(LOG_ALL);
  InitWindow(800, 480, "Labirintos do INF");
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  auto menus = std::make_unique<Menus>();
  auto game = std::make_unique<StateMachine>(std::move(menus));

  game->run();

  CloseWindow();

  return 0;
}
