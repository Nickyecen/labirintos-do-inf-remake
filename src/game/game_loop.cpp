#include "game_loop.hpp"
#include <queue>
#include <raylib.h>

GameLoop::GameLoop(std::unique_ptr<GNode> tree) : _tree(std::move(tree)) {
  _is3D = false;

  std::queue<GNode *> findCamera;
  findCamera.push(_tree.get());
  GNode *cur;
  while (!findCamera.empty()) {
    cur = findCamera.front();
    findCamera.pop();
    if (cur->getName() == "Camera3D") {
      _is3D = true;
      // TODO
      return;
    }
  }
}

bool GameLoop::isFinal() const { return false; }

void GameLoop::enter() {}

std::unique_ptr<State> GameLoop::update() {
  std::queue<GNode *> toUpdate;
  std::queue<GNode *> toDraw2D;
  std::queue<GNode *> toDraw3D;

  toUpdate.push(_tree.get());
  toDraw2D.push(_tree.get());
  toDraw3D.push(_tree.get());

  GNode *cur;
  while (!toUpdate.empty()) {
    cur = toUpdate.front();
    toUpdate.pop();

    // TODO - will only be correct with the Camera3D node
    if (!_is3D && cur->getName() == "Camera3D") {
      _is3D = true;
    }

    for (auto &child : cur->_childrenList) {
      toUpdate.push(child.get());
      toDraw2D.push(child.get());
      toDraw3D.push(child.get());
    }

    cur->update();
  }

  BeginDrawing();

  while (!toDraw2D.empty()) {
    cur = toDraw2D.front();
    toDraw2D.pop();

    cur->draw2D();
  }

  // TODO - will only be correct with the Camera3D node
  if (!_is3D) {
    EndDrawing();
    return nullptr;
  }

  BeginMode3D(*_camera);
  while (!toDraw3D.empty()) {
    cur = toDraw3D.front();
    toDraw3D.pop();

    cur->draw3D();
  }
  EndMode3D();

  EndDrawing();

  return nullptr;
}

void GameLoop::exit() {}
