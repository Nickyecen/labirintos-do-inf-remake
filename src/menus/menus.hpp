#ifndef MENUS_HEADER
#define MENUS_HEADER

#include "../state-machines/state.hpp"
#include "../state-machines/state_machine.hpp"
#include <memory>
#include <raylib.h>

class Menus : public State {
private:
  std::unique_ptr<StateMachine> _interfaceStateMachine;
  bool _shouldStop = false;

public:
  virtual bool isFinal() const override;
  virtual void enter() override;
  virtual std::unique_ptr<State> update() override;
  virtual void exit() override;

  virtual bool shouldStop() const override {
    return _shouldStop || WindowShouldClose();
  }
  void setShouldStop(bool shouldStop) { _shouldStop = shouldStop; }
};

#endif
