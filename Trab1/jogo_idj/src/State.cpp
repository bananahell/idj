/**
 * @file State.cpp
 *
 * Game's logic coordinator.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#define INCLUDE_SDL
#include "SDL_include.h"

#include "State.h"

#include "Game.h"

State::State() : bg(Sprite()), music(Music()) { State::quitRequested = false; }

void State::LoadAssets() {
  /* Sprite assets. */
  State::bg.Open("assets/img/ocean.jpg");

  /* Music assets. */
  State::music.Open("assets/music/stageState.ogg");
  State::music.Play();
}

void State::Update() {
  if (SDL_QuitRequested() == true) {
    /* Quitting the game. */
    State::quitRequested = true;
  }
}

void State::Render() {
  /* Rendering background in top left corner. */
  State::bg.Render(0, 0);
}

bool State::QuitRequested() { return State::quitRequested; }
