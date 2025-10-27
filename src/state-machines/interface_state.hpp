#ifndef INTERFACE_STATE_HEADER
#define INTERFACE_STATE_HEADER

#include "state.hpp"

class InterfaceState : public State {
public:
  virtual ~InterfaceState() = default;
  virtual bool shouldDraw() const = 0;
  virtual void draw() const = 0;
};

#endif
