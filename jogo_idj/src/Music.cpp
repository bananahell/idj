/**
 * @file Music.cpp
 * 
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#define INCLUDE_SDL
#include "SDL_include.h"

#include "Music.h"


Music::Music() {

  Music::music = nullptr;

}

Music::Music(std::string file) {

  Music::Open(file);

}

void Music::Play(int times) {

  Mix_PlayMusic(Music::music, times);

}

void Music::Stop(int msToStop) {

  Mix_FadeOutMusic(msToStop);

}

void Music::Open(std::string file) {

  Music::music = Mix_LoadMUS(file.c_str());
  if (Music::music == nullptr) {
    SDL_Log("Unable to load music Mix_LoadMUS: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

}

bool Music::IsOpen() {

  if (Music::music != nullptr) {
    return true;
  }
  return false;

}
