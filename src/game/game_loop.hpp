#pragma once

#include "../state-machines/state.hpp"
#include "level.hpp"
#include <memory>
#include <raylib.h>

class GameLoop : public State {
private:
  const std::unique_ptr<Level> _level;
  bool _shouldStop = false;

public:
  GameLoop(std::unique_ptr<Level> level) : _level(std::move(level)) {}

  virtual bool isFinal() const override;
  virtual void enter() override;
  virtual std::unique_ptr<State> update() override;
  virtual void exit() override;

  virtual bool shouldStop() const override {
    return _shouldStop || WindowShouldClose();
  }
  void setShouldStop(bool shouldStop) { _shouldStop = shouldStop; }
};
