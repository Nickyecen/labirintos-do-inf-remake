#ifndef MENUS_HEADER
#define MENUS_HEADER

#include "../state-machines/state.hpp"
#include <memory>
#include <raylib.h>

// Initial game state with main menus
class Menus : public State {
private:
  bool _shouldStop = false;

public:
  // Overrides abstract methods
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
