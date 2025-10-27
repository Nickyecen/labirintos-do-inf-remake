#ifndef STATE_MACHINE_HEADER
#define STATE_MACHINE_HEADER

#include "state.hpp"

class StateMachine {
private:
  std::unique_ptr<State> _currentState;

public:
  StateMachine(std::unique_ptr<State> initialState);
  virtual void run();

  State *getCurrentState() const { return _currentState.get(); }
};

#endif
