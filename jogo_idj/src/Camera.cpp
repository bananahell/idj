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
Vec2 Camera::pos = Vec2(0, 0);
Vec2 Camera::speed = Vec2(300, 300);

void Camera::Follow(GameObject* newFocus) {

  Camera::focus = newFocus;

}

void Camera::Unfollow() {

  Camera::focus = nullptr;

}

void Camera::Update(float dt) {

  if (Camera::focus != nullptr) {

    if (InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)) {
      Camera::focus->box.y -= Camera::speed.y * dt;
    }
    if (InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)) {
      Camera::focus->box.y += Camera::speed.y * dt;
    }
    if (InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)) {
      Camera::focus->box.x -= Camera::speed.x * dt;
    }
    if (InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)) {
      Camera::focus->box.x += Camera::speed.x * dt;
    }
    int w, h;
    SDL_GetRendererOutputSize(Game::GetInstance().GetRenderer(), &w, &h);
    Camera::pos.x = (Camera::focus->box.x + (Camera::focus->box.w / 2)) - (w / 2);
    Camera::pos.y = (Camera::focus->box.y + (Camera::focus->box.h / 2)) - (h / 2);

  } else {

    if (InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)) {
      Camera::pos.y -= Camera::speed.y * dt;
    }
    if (InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)) {
      Camera::pos.y += Camera::speed.y * dt;
    }
    if (InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)) {
      Camera::pos.x -= Camera::speed.x * dt;
    }
    if (InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)) {
      Camera::pos.x += Camera::speed.x * dt;
    }

  }

}
