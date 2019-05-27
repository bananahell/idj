/**
 * @file Music.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Music.h"

Music::Music() { Music::music = nullptr; }

Music::Music(std::string file) { Music::Open(file); }

void Music::Play(int times) { Mix_PlayMusic(Music::music, times); }

void Music::Stop(int msToStop) { Mix_FadeOutMusic(msToStop); }

void Music::Open(std::string file) { Music::music = Mix_LoadMUS(file.c_str()); }

bool Music::IsOpen() {
  if (Music::music != nullptr) {
    return true;
  }
  return false;
}
