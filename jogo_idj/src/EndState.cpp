#include "EndState.h"

#include "CameraFollower.h"
#include "Game.h"
#include "GameData.h"
#include "InputManager.h"
#include "Sprite.h"
#include "StageState.h"
#include "Text.h"


EndState::EndState() : State() {

  EndState::bg = new GameObject();
  EndState::txt = new GameObject();

  if (GameData::playerVictory) {
    EndState::bg->AddComponent(new Sprite(*bg, "assets/img/win.jpg"));
    EndState::bg->AddComponent(new CameraFollower(*bg));
    EndState::bg->box.SetSize(Vec2());

    EndState::txt->AddComponent(new Text(*txt, "assets/font/Call me maybe.ttf", 72, "PRESS SPACE TO TRY AGAIN", SDL_Color {}, Text::SOLID));
    EndState::txt->AddComponent(new CameraFollower(*txt, Vec2(512, 500)-(EndState::txt->box.GetSize()/2)));

    EndState::backgroundMusic = Music("assets/audio/endStateWin.ogg");
  } else {
    EndState::bg->AddComponent(new Sprite(*bg, "assets/img/lose.jpg"));
    EndState::bg->AddComponent(new CameraFollower(*bg));
    EndState::bg->box.SetSize(Vec2());

    EndState::txt->AddComponent(new Text(*txt, "assets/font/Call me maybe.ttf", 72, "PRESS SPACE TO TRY AGAIN", SDL_Color {255, 255, 255, 0}, Text::SOLID));
    EndState::txt->AddComponent(new CameraFollower(*txt, Vec2(512, 100)-(EndState::txt->box.GetSize()/2)));

    EndState::backgroundMusic = Music("assets/audio/endStateLose.ogg");
  }

}

EndState::~EndState() {

  delete EndState::bg;
  delete EndState::txt;

}

void EndState::LoadAssets() {


}

void EndState::Start() {

  LoadAssets();
  EndState::bg->Start();
  EndState::txt->Start();
  StartArray();
  EndState::backgroundMusic.Play();
  EndState::started = true;

}

void EndState::Pause() {


}

void EndState::Resume() {


}

void EndState::Update(float dt) {

  EndState::quitRequested = InputManager::QuitRequested();
  if (InputManager::KeyPress(ESCAPE_KEY)) {
    EndState::quitRequested = true;
  }

  if (InputManager::KeyPress(SPACE_KEY)) {
    EndState::popRequested = true;
  }

  if (EndState::bg->IsActive()) {
    EndState::bg->Update(dt);
  }
  if (EndState::txt->IsActive()) {
    EndState::txt->Update(dt);
  }
  UpdateArray(dt);

}

void EndState::Render() {

  if (EndState::bg->IsActive()) {
    EndState::bg->Render();
  }
  if (EndState::txt->IsActive()) {
    EndState::txt->Render();
  }
  RenderArray();

}
