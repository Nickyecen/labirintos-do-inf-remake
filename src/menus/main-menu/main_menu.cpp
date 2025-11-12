#include "main_menu.hpp"
#include "../../render/renderer.hpp"
#include "../../ui/button.hpp"
#include "../../ui/column.hpp"
#include "../../ui/hsplit.hpp"
#include "../../ui/label.hpp"
#include "raylib.h"
#include <memory>

MainMenuState::MainMenuState() {
  auto newGameLabel = std::make_unique<Label>("Novo Jogo", BUTTON_SIZE, WHITE,
                                              RenderPosition::CENTER);
  Label *newGameLabelPtr = newGameLabel.get();

  auto continueLabel = std::make_unique<Label>("Continuar", BUTTON_SIZE, WHITE,
                                               RenderPosition::CENTER);
  Label *continueLabelPtr = continueLabel.get();

  auto optionsLabel = std::make_unique<Label>("Opções", BUTTON_SIZE, WHITE,
                                              RenderPosition::CENTER);
  Label *optionsLabelPtr = optionsLabel.get();

  auto quitLabel = std::make_unique<Label>("Sair", BUTTON_SIZE, WHITE,
                                           RenderPosition::CENTER);
  Label *quitLabelPtr = quitLabel.get();

  auto newGame = std::make_unique<Button>(std::move(newGameLabel));
  auto contin = std::make_unique<Button>(std::move(continueLabel));
  auto options = std::make_unique<Button>(std::move(optionsLabel));
  auto quit = std::make_unique<Button>(std::move(quitLabel));

  newGame->onHover = [newGameLabelPtr](const int x, const int y) {
    newGameLabelPtr->setColor(GRAY);
  };
  newGame->onNotHover = [newGameLabelPtr](const int x, const int y) {
    newGameLabelPtr->setColor(WHITE);
  };
  newGame->onLeftDown = [newGameLabelPtr](const int x, const int y) {
    newGameLabelPtr->setColor(DARKGRAY);
  };

  contin->onHover = [continueLabelPtr](const int x, const int y) {
    continueLabelPtr->setColor(GRAY);
  };
  contin->onNotHover = [continueLabelPtr](const int x, const int y) {
    continueLabelPtr->setColor(WHITE);
  };
  contin->onLeftDown = [continueLabelPtr](const int x, const int y) {
    continueLabelPtr->setColor(DARKGRAY);
  };

  options->onHover = [optionsLabelPtr](const int x, const int y) {
    optionsLabelPtr->setColor(GRAY);
  };
  options->onNotHover = [optionsLabelPtr](const int x, const int y) {
    optionsLabelPtr->setColor(WHITE);
  };
  options->onLeftDown = [optionsLabelPtr](const int x, const int y) {
    optionsLabelPtr->setColor(DARKGRAY);
  };

  bool *doQuit = &_shouldStop;
  quit->onHover = [quitLabelPtr](const int x, const int y) {
    quitLabelPtr->setColor(GRAY);
  };
  quit->onNotHover = [quitLabelPtr](const int x, const int y) {
    quitLabelPtr->setColor(WHITE);
  };
  quit->onLeftDown = [quitLabelPtr](const int x, const int y) {
    quitLabelPtr->setColor(DARKGRAY);
  };
  quit->onLeftRelease = [doQuit](const int x, const int y) { *doQuit = true; };

  auto buttons = std::make_unique<Column>();
  buttons->add(std::move(newGame))
      ->add(std::move(contin))
      ->add(std::move(options))
      ->add(std::move(quit));

  _content = std::make_unique<HSplit>(
      std::make_unique<Label>("Labirintos do INF", TITLE_SIZE, WHITE,
                              RenderPosition::CENTER),
      std::move(buttons), 0.4);
  _content->setTL((Vector2){0, 0});
  _content->setBR((Vector2){(float)GetRenderWidth(), (float)GetRenderHeight()});
  _content->refresh();
}
MainMenuState::~MainMenuState() {}

bool MainMenuState::shouldDraw() const { return true; }

bool MainMenuState::shouldStop() const {
  return _shouldStop || WindowShouldClose();
}

bool MainMenuState::isFinal() const { return false; }

void MainMenuState::enter() {
  _backgroundTexture = LoadTexture("res/images/placeholder_background.jpg");
}

std::unique_ptr<State> MainMenuState::update() {
  _content->refresh();
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
