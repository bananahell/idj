/**
 * @file Sound.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Sound.h"


Sound::Sound(GameObject& associated) : Component(associated) {

  // TODO Atribui o associated ao atributo de mesmo nome e atribui nullptr a chunk.?????????

}

Sound::Sound(GameObject& associated, std::string file) : Component(associated) {

  // Sound::Sound(associated); // TODO ??

}

void Sound::Play(int times) {

  // TODO int Mix_PlayChannel(int channel = -1, Mix_Chunk* chunk, int loops = times - 1)

}

void Sound::Stop() {

  // TODO int Mix_HaltChannel(int channel) ???

}

void Sound::Open(std::string file) {

  // TODO Mix_Chunk* Mix_LoadWAV(char* file = file.c_str())

}

Sound::~Sound() {

  // TODO void Mix_FreeChunk(Mix_Chunk* chunk)

}

void Sound::Update(float dt) {

// TODO ??

}

void Sound::Render() {

// TODO ??

}

bool Sound::Is(std::string type) {

// TODO ??

}
