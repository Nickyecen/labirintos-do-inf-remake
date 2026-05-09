#ifndef STATE_HEADER
#define STATE_HEADER

#include <memory>

// Abstract State class
class State {
public:
  virtual ~State() = default;

  // Sets state as final state for successfull run
  virtual bool isFinal() const = 0;

  // Execution when entering the state
  virtual void enter() = 0;

  // Execution in loop while returning nullptr, then exits
  virtual std::unique_ptr<State> update() = 0;

  // Execution when leaving state after update returned a new state
  virtual void exit() = 0;

  // Calls for the SM to stop
  virtual bool shouldStop() const = 0;
};

#endif
