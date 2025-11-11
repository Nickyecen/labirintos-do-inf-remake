#ifndef RENDERER_HEADER
#define RENDERER_HEADER
#include "raylib.h"

enum RenderPosition {
  TOP_LEFT,
  TOP_CENTER,
  TOP_RIGHT,
  CENTER_LEFT,
  CENTER,
  CENTER_RIGHT,
  BOTTOM_LEFT,
  BOTTOM_CENTER,
  BOTTOM_RIGHT
};

enum RenderScale {
  KEEP,
  KEEP_PROPORTION_FILL,
  KEEP_PROPORTION_FIT,
};

class Renderer {
private:
  Renderer();
  static Vector2 _getRelativePosition(int width, int height,
                                      RenderPosition position);

public:
  static void renderTexture2D(Texture2D texture, RenderPosition position,
                              RenderScale scale);
};

#endif
