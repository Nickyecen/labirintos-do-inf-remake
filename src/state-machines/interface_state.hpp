#ifndef INTERFACE_STATE_HEADER
#define INTERFACE_STATE_HEADER

#include "state.hpp"

// Abstract InterfaceState class
class InterfaceState : public State {
public:
  virtual ~InterfaceState() = default;

  // Checks if interface should draw something in current loop
  virtual bool shouldDraw() const = 0;

  // If shouldDraw, calls this draw function
  virtual void draw() const = 0;
};

#endif
