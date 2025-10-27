#ifndef AUDIO_HEADER
#define AUDIO_HEADER

#include <raylib.h>
#include <string>

class Audio {
public:
private:
public:
  Audio(const Audio &) = delete;
  Audio &operator=(const Audio &) = delete;

  static Audio &get();
  static void close();

  void playSound(const Sound sound) const;
  Sound loadSound(const std::string fileName) const;

private:
  Audio();
  ~Audio();
};

#endif
