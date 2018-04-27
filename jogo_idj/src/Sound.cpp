/**
 * @file Sound.cpp
 *
 * Game's sounds manager. They are the game's objects' sound components.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Sound.h"

#include "Resources.h"


Sound::Sound(GameObject& associated) : Component(associated) {

  Sound::chunk = nullptr;
  Sound::channel = -1;

}

Sound::Sound(GameObject& associated, std::string file) : Sound(associated) {

  Sound::Open(file);

}

void Sound::Play(int times) {

  Sound::channel = Mix_PlayChannel(-1, Sound::chunk, times - 1);
  if (Sound::channel == -1) {
    SDL_Log("Unable to play sound Mix_PlayChannel: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

}

void Sound::Stop() {

  if (Sound::chunk != nullptr) {
    if (Mix_HaltChannel(Sound::channel) != 0) {
      SDL_Log("HOW DID THIS BREAK?? Mix_HaltChannel: %s", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  }

}

void Sound::Open(std::string file) {

  Sound::chunk = Resources::GetSound(file);

}

Sound::~Sound() {


}

void Sound::Update(float dt) {

}

bool Sound::GetIsPlaying() {

  return Mix_Playing(Sound::channel) > 0;

}

void Sound::Render(Vec2 cameraPos) {


}

bool Sound::Is(std::string type) {

  if (type.compare("Sound") == 0) {
    return true;
  }
  return false;

}
