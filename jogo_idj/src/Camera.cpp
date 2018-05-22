/**
 * @file Camera.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Camera.h"

#include "Game.h"
#include "InputManager.h"


GameObject* Camera::focus = nullptr;
Vec2 Camera::pos = Vec2();
Vec2 Camera::speed = Vec2(300, 300);

void Camera::Follow(GameObject* newFocus) {

  Camera::focus = newFocus;

}

void Camera::Unfollow() {

  Camera::focus = nullptr;

}

void Camera::Update(float dt) {

  if (!(Camera::focus)) {

    if (InputManager::IsKeyDown(UP_ARROW_KEY)) {
      Camera::pos.y -= Camera::speed.y * dt;
    }
    if (InputManager::IsKeyDown(DOWN_ARROW_KEY)) {
      Camera::pos.y += Camera::speed.y * dt;
    }
    if (InputManager::IsKeyDown(LEFT_ARROW_KEY)) {
      Camera::pos.x -= Camera::speed.x * dt;
    }
    if (InputManager::IsKeyDown(RIGHT_ARROW_KEY)) {
      Camera::pos.x += Camera::speed.x * dt;
    }

  } else {

    int w, h;
    SDL_GetRendererOutputSize(Game::GetInstance().GetRenderer(), &w, &h);
    Camera::pos.x = Camera::focus->box.GetCenter().x - w/2;
    Camera::pos.y = Camera::focus->box.GetCenter().y - h/2;

  }

}

GameObject* Camera::GetFocus() {

  return focus;

}
