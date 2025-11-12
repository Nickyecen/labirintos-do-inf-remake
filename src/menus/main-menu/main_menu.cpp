#include "main_menu.hpp"
#include "../../audio/audio.hpp"
#include "../../render/renderer.hpp"
#include "../../ui/button.hpp"
#include "../../ui/column.hpp"
#include "../../ui/frame.hpp"
#include "../../ui/hsplit.hpp"
#include "../../ui/label.hpp"
#include "raylib.h"
#include <memory>

MainMenuState::MainMenuState() {
  _hoverSound = Audio::get().loadSound("./res/sound/ui_hover.mp3");
  _cancelSound = Audio::get().loadSound("./res/sound/ui_cancel.mp3");
  _selectSound = Audio::get().loadSound("./res/sound/ui_select.mp3");

  std::unique_ptr<UINode> buttons = _createButtons();

  _content = std::make_unique<Frame>(std::make_unique<HSplit>(
      std::make_unique<Label>("Labirintos do INF", TITLE_SIZE, WHITE,
                              RenderPosition::CENTER),
      std::move(buttons), 0.4));
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

std::unique_ptr<Button> MainMenuState::_makeButton(std::string text,
                                                   Sound &hover) {
  auto label =
      std::make_unique<Label>(text, BUTTON_SIZE, WHITE, RenderPosition::CENTER);
  Label *labelPtr = label.get();

  auto button = std::make_unique<Button>(std::move(label));

  button->onHover = [labelPtr, hover](const int x, const int y) {
    Audio::get().playSound(hover);
    labelPtr->setColor(GRAY);
  };
  button->onNotHover = [labelPtr](const int x, const int y) {
    labelPtr->setColor(WHITE);
  };
  button->onLeftClick = [labelPtr](const int x, const int y) {
    labelPtr->setColor(DARKGRAY);
  };
  button->onLeftRelease = [labelPtr](const int x, const int y) {
    labelPtr->setColor(GRAY);
  };

  return button;
}

std::unique_ptr<UINode> MainMenuState::_createButtons() {
  auto newGame = _makeButton("Novo Jogo", _hoverSound);
  auto contin = _makeButton("Continuar", _hoverSound);
  auto options = _makeButton("Opções", _hoverSound);
  auto quit = _makeButton("Sair", _hoverSound);

  bool *doQuit = &_shouldStop;
  quit->onLeftRelease = [doQuit](const int x, const int y) { *doQuit = true; };

  auto buttons = std::make_unique<Column>();
  buttons->add(std::move(newGame))
      ->add(std::move(contin))
      ->add(std::move(options))
      ->add(std::move(quit));

  return buttons;
}
