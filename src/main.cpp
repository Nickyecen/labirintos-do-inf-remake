#include "menus/menus.hpp"
#include "state-machines/state_machine.hpp"
#include <bits/unique_ptr.h>
#include <raylib.h>

// Constants
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 480
#define DEFAULT_WINDOW_TITLE "Labirintos do INF"

// Main function
int main() {
  using namespace std;

#ifdef DEBUG
  SetTraceLogLevel(LOG_ALL);
#else
  SetTraceLogLevel(LOG_INFO);
#endif // DEBUG

  // Creates window
  InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, DEFAULT_WINDOW_TITLE);
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  // Creates menus
  unique_ptr<Menus> menus = make_unique<Menus>();
  TraceLog(LOG_DEBUG, "Created menus, starting game SM");
  // Starts game
  unique_ptr<StateMachine> game = make_unique<StateMachine>(std::move(menus));

  game->run();

  // After game is finished, close
  CloseWindow();

  return 0;
}
