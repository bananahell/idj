#include "Sound.h"

#include "Resources.h"


Sound::Sound(GameObject& associated) : Component(associated) {

  Sound::chunk = nullptr;
  Sound::channel = -1;

}

Sound::Sound(GameObject& associated, std::string file) : Sound(associated) {

  Open(file);

}

Sound::~Sound() {

  Stop();
  Sound::chunk = nullptr;

}

void Sound::Open(std::string file) {

  Sound::chunk = Resources::GetSound(file);

}

void Sound::Play(int times) {

  Sound::channel = Mix_PlayChannel(Sound::channel, Sound::chunk.get(), times - 1);
  if (Sound::channel == -1) {
    printf("Mix_PlayChannel failed: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

}

void Sound::Stop() {

  if (IsPlaying()) {
    Mix_HaltChannel(Sound::channel);
  }

}

void Sound::Update(float dt) {


}

void Sound::Render() {


}

bool Sound::Is(std::string type) {

  if (type.compare("Sound") == 0) {
    return true;
  }
  return false;

}

bool Sound::IsOpen() {

  if (Sound::chunk == nullptr) {
    return false;
  }
  return true;

}

bool Sound::IsPlaying() {

  return (Mix_Playing(Sound::channel));

}
