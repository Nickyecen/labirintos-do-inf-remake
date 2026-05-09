#include "main_menu.hpp"
#include "../../audio/audio.hpp"
#include "../../ui/button.hpp"
#include "../../ui/column.hpp"
#include "../../ui/frame.hpp"
#include "../../ui/hsplit.hpp"
#include "../../ui/overlay.hpp"
#include "../../ui/image_frame.hpp"
#include "../../ui/label.hpp"
#include "raylib.h"
#include <memory>
#include <string>

// Sound string file localizations
#define HOVER_SOUND_FILE_STR "./res/sound/ui_hover.mp3"
#define CANCEL_SOUND_FILE_STR "./res/sound/ui_cancel.mp3"
#define SELECT_SOUND_FILE_STR "./res/sound/ui_select.mp3"

#define BACKGROUND_IMAGE_FILE_STR "res/images/placeholder_background.png"

#define GAME_TITLE "Labirintos do INF"

MainMenuState::MainMenuState() {
  // Loads used sounds
  _hoverSound = Audio::get().loadSound(HOVER_SOUND_FILE_STR);
  _cancelSound = Audio::get().loadSound(CANCEL_SOUND_FILE_STR);
  _selectSound = Audio::get().loadSound(SELECT_SOUND_FILE_STR);
  TraceLog(LOG_DEBUG, "Loaded Main Menu sounds");

  // Creates available buttons
  std::unique_ptr<UINode> buttons = _createButtons();
  TraceLog(LOG_DEBUG, "Created Main Menu buttons");

  // Creates interface
  _content = std::make_unique<Frame>( // Main Frame
              std::make_unique<Overlay>( // Overlay title on image
                std::make_unique<ImageFrame>( // Background image
                  BACKGROUND_IMAGE_FILE_STR,
                  UINode::Position::CENTER,
                  UINode::Scale::KEEP_PROPORTION_FILL
                ),
                std::make_unique<HSplit>( // Horizontal split
                  std::make_unique<Label>( // Title on top
                    GAME_TITLE,
                    TITLE_SIZE,
                    WHITE,
                    UINode::Position::CENTER
                  ),
                  std::move(buttons), // Buttons on the bottom
                  0.4 // Split localization
                )
              )
            );
  TraceLog(LOG_DEBUG, "Created Main Menu content");
}

MainMenuState::~MainMenuState() {}

// TODO Better draw logic for no unnecessary redrawing
bool MainMenuState::shouldDraw() const { return true; }

bool MainMenuState::shouldStop() const {
  return _shouldStop || WindowShouldClose();
}

bool MainMenuState::isFinal() const { return false; }

// On enter, loads background image
void MainMenuState::enter() {
  TraceLog(LOG_DEBUG, "Entering Main Menu state...");
  _backgroundTexture = LoadTexture(BACKGROUND_IMAGE_FILE_STR);
  TraceLog(LOG_DEBUG, "Entered Main Menu state");
}

std::unique_ptr<State> MainMenuState::update() {
  _content->refresh();
  if (this->shouldDraw())
    this->draw();
  return nullptr;
}

void MainMenuState::draw() const {
  BeginDrawing();
  ClearBackground(this->_BACKGROUND_COLOR);
  _content->draw();
  EndDrawing();
}

void MainMenuState::exit() { TraceLog(LOG_DEBUG, "Exit Main Menu"); }

std::unique_ptr<Button> MainMenuState::_makeButton(std::string const text,
                                                   Sound const &hover) {
  std::unique_ptr<Label> label =
      std::make_unique<Label>(text, BUTTON_SIZE, WHITE, UINode::Position::CENTER);
  Label *labelPtr = label.get();

  std::unique_ptr<Button> button = std::make_unique<Button>(std::move(label));

  // Makes hover play hover sound and darken
  button->onHover = [labelPtr, hover](const int x, const int y) {
    Audio::get().playSound(hover);
    labelPtr->setColor(GRAY);
  };
  // Makes leave hover recolor white
  button->onNotHover = [labelPtr](const int x, const int y) {
    labelPtr->setColor(WHITE);
  };
  // Makes left click darken
  button->onLeftClick = [labelPtr](const int x, const int y) {
    labelPtr->setColor(DARKGRAY);
  };
  // Makes left click release hover color
  button->onLeftRelease = [labelPtr](const int x, const int y) {
    labelPtr->setColor(GRAY);
  };

  // Returns created button
  return button;
}

std::unique_ptr<UINode> MainMenuState::_createButtons() {
  // Strings for text displayed in the buttons
  std::string const _NEW_GAME_STRING = "Novo Jogo";
  std::string const _CONTINUE_STRING = "Continuar";
  std::string const _SETTINGS_STRING = "Configurações";
  std::string const _QUIT_STRING = "Sair";

  // Available main menu buttons
  auto newGame = _makeButton(_NEW_GAME_STRING, _hoverSound);
  auto contin = _makeButton(_CONTINUE_STRING, _hoverSound);
  auto settings = _makeButton(_SETTINGS_STRING, _hoverSound);
  auto quit = _makeButton(_QUIT_STRING, _hoverSound);

  // Adds quit functionality to quit button
  bool *doQuit = &_shouldStop;
  quit->onLeftRelease = [doQuit](const int x, const int y) { *doQuit = true; };

  // Create button column with available buttons
  auto buttons = std::make_unique<Column>();
  buttons->add(std::move(newGame))
      ->add(std::move(contin))
      ->add(std::move(settings))
      ->add(std::move(quit));

  // Returns button column
  return buttons;
}
