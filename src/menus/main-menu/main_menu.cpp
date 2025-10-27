#include "main_menu.hpp"
#include "raylib.h"

MainMenuState::MainMenuState() {}
MainMenuState::~MainMenuState() {}

bool MainMenuState::shouldDraw() const { return true; }

bool MainMenuState::shouldStop() const { return WindowShouldClose(); }

bool MainMenuState::isFinal() const { return false; }

void MainMenuState::enter() {
  _backgroundTexture = LoadTexture("res/images/placeholder_background.jpg");
}

std::unique_ptr<State> MainMenuState::update() {
  if (this->shouldDraw())
    this->draw();
  return nullptr;
}

void MainMenuState::draw() const {
  BeginDrawing();
  ClearBackground(this->_backgroundColor);
  Renderer::renderTexture2D(_backgroundTexture, RenderPosition::CENTER,
                            RenderScale::KEEP_PROPORTION_FILL);
  EndDrawing();
}

void MainMenuState::exit() { TraceLog(LOG_DEBUG, "Exited state"); }
