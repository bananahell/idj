/**
 * @file Music.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Music.h"

#include "Resources.h"


Music::Music() : music(nullptr) {


}

Music::Music(std::string file) : Music() {

  Music::Open(file);

}

Music::~Music() {

  if (Music::IsPlaying()) {
    Music::Stop(0);
  }
  Music::music = nullptr;

}

void Music::Play(int times) {

  if (Mix_PlayMusic(music.get(), times) == -1) {
    SDL_Log("Unable to play music: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

}

void Music::Stop(int msToStop) {

  if (!Mix_FadeOutMusic(msToStop)) {
    SDL_Log("Unable to stop music: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

}

void Music::Open(std::string file) {

  music = Resources::GetMusic(file);

}

bool Music::IsOpen() {

  if (Music::music != nullptr) {
    return true;
  }
  return false;

}

bool Music::IsPlaying() {

  return (Mix_PlayingMusic());

}
