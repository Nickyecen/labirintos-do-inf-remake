#include "state_machine.hpp"
#include <memory>
#include <raylib.h>

// Constructs SM with initial running state
StateMachine::StateMachine(std::unique_ptr<State> initialState)
    : _currentState(std::move(initialState)) {
  _currentState->enter();
}

// Runs the state machine
void StateMachine::run() {
  // Updates states until SM ends
  while (!_currentState->shouldStop()) {
    // Updates state
    std::unique_ptr<State> newState = _currentState->update();

    // Checks if went to new state
    if (newState) {
      // If so, exits current states and enters new one
      this->_currentState->exit();
      this->_currentState = std::move(newState);
      this->_currentState->enter();
    }
  }
}
