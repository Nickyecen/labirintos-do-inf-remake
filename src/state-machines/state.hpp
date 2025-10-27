#ifndef STATE_HEADER
#define STATE_HEADER

#include <memory>

class State {
public:
  virtual ~State() = default;

  virtual bool isFinal() const = 0;

  virtual void enter() = 0;
  virtual std::unique_ptr<State> update() = 0;
  virtual void exit() = 0;

  virtual bool shouldStop() const = 0;
};

#endif
