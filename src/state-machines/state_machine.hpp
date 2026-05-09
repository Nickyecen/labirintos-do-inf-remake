#ifndef STATE_MACHINE_HEADER
#define STATE_MACHINE_HEADER

#include "state.hpp"

class StateMachine {
private:
  // The running state of the SM
  std::unique_ptr<State> _currentState;

public:
  // Constructs SM with initial running state
  StateMachine(std::unique_ptr<State> initialState);

  // Runs the state machine
  virtual void run();

  // Gets a pointer to the current running state in the SM
  State *getCurrentState() const { return _currentState.get(); }
};

#endif
