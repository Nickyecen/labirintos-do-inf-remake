#include "main_menu.hpp"
#include "../../render/renderer.hpp"
#include "../../ui/column.hpp"
#include "../../ui/hsplit.hpp"
#include "../../ui/label.hpp"
#include "raylib.h"
#include <memory>

MainMenuState::MainMenuState() {

  auto buttons = std::make_unique<Column>();
  buttons
      ->add(std::make_unique<Label>("Button 1", 24, (Color){255, 255, 255, 255},
                                    RenderPosition::CENTER))
      ->add(std::make_unique<Label>("Button 2", 24, (Color){255, 255, 255, 255},
                                    RenderPosition::CENTER))
      ->add(std::make_unique<Label>("Button 3", 24, (Color){255, 255, 255, 255},
                                    RenderPosition::CENTER));
  _content = std::make_unique<HSplit>(
      std::make_unique<Label>("Título", TITLE_SIZE, (Color){255, 255, 255, 255},
                              RenderPosition::CENTER),
      std::move(buttons), 0.2);
  _content->setTL((Vector2){0, 0});
  _content->setBR((Vector2){(float)GetRenderWidth(), (float)GetRenderHeight()});
  _content->refresh();
}
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
  _content->draw();
  EndDrawing();
}

void MainMenuState::exit() { TraceLog(LOG_DEBUG, "Exited state"); }
