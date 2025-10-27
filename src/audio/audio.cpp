#include "audio.hpp"
#include <memory>

Audio::Audio() {}
Audio::~Audio() {}

Audio &Audio::get() {
  if (!IsAudioDeviceReady()) {
    InitAudioDevice();
    if (!IsAudioDeviceReady()) {
      TraceLog(LOG_ERROR, "Audio class could not be initialized");
    }
  }
  static Audio instance;
  return instance;
}

void Audio::close() {
  if (IsAudioDeviceReady())
    CloseAudioDevice();
}

void Audio::playSound(Sound sound) const { PlaySound(sound); }

Sound Audio::loadSound(const std::string fileName) const {
  return LoadSound(fileName.c_str());
}
