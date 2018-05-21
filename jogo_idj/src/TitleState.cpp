#include "TitleState.h"

#include "CameraFollower.h"
#include "Game.h"
#include "InputManager.h"
#include "Sprite.h"
#include "StageState.h"
#include "Text.h"


TitleState::TitleState() : State() {

  TitleState::bg = new GameObject();
  TitleState::txt = new GameObject();

  TitleState::bg->AddComponent(new Sprite(*bg, "assets/img/title.jpg"));
  TitleState::bg->AddComponent(new CameraFollower(*bg));
  TitleState::bg->box.SetSize(Vec2());

  TitleState::txt->AddComponent(new Text(*txt, "assets/font/Call me maybe.ttf", 72, "PRESS SPACE TO CONTINUE", SDL_Color {}, Text::SOLID));
  TitleState::txt->AddComponent(new CameraFollower(*txt, Vec2(512, 500)-(txt->box.GetSize()/2)));

}

TitleState::~TitleState() {

  delete TitleState::bg;
  delete TitleState::txt;

}

void TitleState::LoadAssets() {


}

void TitleState::Start() {

  LoadAssets();
  TitleState::bg->Start();
  TitleState::txt->Start();
  StartArray();
  TitleState::started = true;

}

void TitleState::Pause() {


}

void TitleState::Resume() {


}

void TitleState::Update(float dt) {

  TitleState::quitRequested = InputManager::QuitRequested();
  if (InputManager::KeyPress(ESCAPE_KEY)) {
    TitleState::quitRequested = true;
  }

  if (InputManager::KeyPress(SPACE_KEY)) {
    Game::GetInstance().Push(new StageState());
  }

  TitleState::toggleText.Update(dt);
  if (TitleState::toggleText.Get() > 0.5) {
    if (TitleState::txt->IsActive()) {
      TitleState::txt->Deactivate();
    } else {
      TitleState::txt->Activate();
    }
    toggleText.Restart();
  }
  if (TitleState::bg->IsActive()) {
    TitleState::bg->Update(dt);
  }
  if (TitleState::txt->IsActive()) {
    TitleState::txt->Update(dt);
  }
  UpdateArray(dt);

}

void TitleState::Render() {

  if (TitleState::bg->IsActive()) {
    TitleState::bg->Render();
  }
  if (TitleState::txt->IsActive()) {
    TitleState::txt->Render();
  }
  RenderArray();

}
