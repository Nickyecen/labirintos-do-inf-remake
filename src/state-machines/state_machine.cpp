#include "state_machine.hpp"
#include <memory>
#include <raylib.h>

StateMachine::StateMachine(std::unique_ptr<State> initialState)
    : _currentState(std::move(initialState)) {
  _currentState->enter();
}

void StateMachine::run() {
  while (!_currentState->shouldStop()) {
    std::unique_ptr<State> newState = _currentState->update();
    if (newState) {
      this->_currentState->exit();
      this->_currentState = std::move(newState);
      this->_currentState->enter();
    }
  }
  TraceLog(LOG_DEBUG, "Exited run");
}
