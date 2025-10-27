#include "renderer.hpp"

void Renderer::renderTexture2D(Texture2D texture, RenderPosition position,
                               RenderScale scale) {
  switch (scale) {
  case RenderScale::KEEP_PROPORTION_FILL: {
    float scaleW = (float)GetScreenWidth() / texture.width;
    float scaleH = (float)GetScreenHeight() / texture.height;
    float scale = scaleW > scaleH ? scaleW : scaleH;
    Vector2 pos = _getRelativePosition(texture.width * scale,
                                       texture.height * scale, position);
    DrawTextureEx(texture, pos, 0, scale, WHITE);
    break;
  }
  case RenderScale::KEEP_PROPORTION_FIT: {
    float scaleW = (float)GetScreenWidth() / texture.width;
    float scaleH = (float)GetScreenHeight() / texture.height;
    float scale = scaleW < scaleH ? scaleW : scaleH;
    Vector2 pos = _getRelativePosition(texture.width * scale,
                                       texture.height * scale, position);
    DrawTextureEx(texture, pos, 0, scale, WHITE);
    break;
  }
  default: {
    Vector2 pos = _getRelativePosition(texture.width, texture.height, position);
    DrawTextureV(texture, pos, WHITE);
  }
  }
}

Vector2 Renderer::_getRelativePosition(int width, int height,
                                       RenderPosition position) {
  int screen_width = GetScreenWidth();
  int screen_height = GetScreenHeight();

  int xPos, yPos;
  switch (position) {
  case RenderPosition::TOP_CENTER:
  case RenderPosition::CENTER:
  case RenderPosition::BOTTOM_CENTER:
    xPos = screen_width / 2 - width / 2;
    break;
  case RenderPosition::TOP_RIGHT:
  case RenderPosition::CENTER_RIGHT:
  case RenderPosition::BOTTOM_RIGHT:
    xPos = screen_width - width;
    break;
  default:
    xPos = 0;
    break;
  }
  switch (position) {
  case RenderPosition::CENTER_LEFT:
  case RenderPosition::CENTER:
  case RenderPosition::CENTER_RIGHT:
    yPos = screen_height / 2 - height / 2;
    break;
  case RenderPosition::BOTTOM_LEFT:
  case RenderPosition::BOTTOM_CENTER:
  case RenderPosition::BOTTOM_RIGHT:
    yPos = screen_height - height;
    break;
  default:
    yPos = 0;
    break;
  }

  return (Vector2){(float)xPos, (float)yPos};
}
