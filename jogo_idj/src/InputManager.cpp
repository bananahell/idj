/**
 * @file InputManager.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "InputManager.h"

#include "Camera.h"


std::unordered_map<int, bool> InputManager::keyState;
std::unordered_map<int, int> InputManager::keyUpdate;
bool InputManager::mouseState [6];
int InputManager::mouseUpdate [6];
int InputManager::mouseX;
int InputManager::mouseY;
int InputManager::updateCounter;
bool InputManager::quitRequested = false;

InputManager& InputManager::GetInstance() {

  static InputManager inputManager;
  return inputManager;

}

InputManager::InputManager() {

  InputManager::mouseX = 0;
  InputManager::mouseY = 0;
  InputManager::updateCounter = 0;
  InputManager::quitRequested = false;

}

InputManager::~InputManager() {


}

void InputManager::Update() {

  InputManager::quitRequested = false;
  SDL_Event event;
  SDL_GetMouseState(&mouseX, &mouseY);
  InputManager::mouseX += Camera::pos.x;
  InputManager::mouseY += Camera::pos.y;

  if (InputManager::updateCounter < 100) {
    InputManager::updateCounter++;
  } else {
    InputManager::updateCounter = 0;
  }

  while (SDL_PollEvent(&event)) {
    if (event.key.repeat != 1) {

      if (event.type == SDL_QUIT) {
        InputManager::quitRequested = true;
      }

      if (event.type == SDL_MOUSEBUTTONDOWN) {
        InputManager::mouseState[event.button.button] = true;
        InputManager::mouseUpdate[event.button.button] = InputManager::updateCounter;
      }
      if (event.type == SDL_MOUSEBUTTONUP) {
        InputManager::mouseState[event.button.button] = false;
        InputManager::mouseUpdate[event.button.button] = InputManager::updateCounter;
      }

      if (event.type == SDL_KEYDOWN) {
        InputManager::keyState[event.key.keysym.sym] = true;
        InputManager::keyUpdate[event.key.keysym.sym] = InputManager::updateCounter;
      }
      if (event.type == SDL_KEYUP) {
        InputManager::keyState[event.key.keysym.sym] = false;
        InputManager::keyUpdate[event.key.keysym.sym] = InputManager::updateCounter;
      }

    }
  }

}

bool InputManager::KeyPress(int key) {

  if (InputManager::keyUpdate[key] == InputManager::updateCounter) {
    return InputManager::keyState[key];
  } else {
    return false;
  }

}

bool InputManager::KeyRelease(int key) {

  if (InputManager::keyUpdate[key] == InputManager::updateCounter) {
    return !(InputManager::keyState[key]);
  } else {
    return false;
  }

}

bool InputManager::IsKeyDown(int key) {

  return InputManager::keyState[key];

}

bool InputManager::MousePress(int button) {

  if (InputManager::mouseUpdate[button] == InputManager::updateCounter) {
    return InputManager::mouseState[button];
  } else {
    return false;
  }

}

bool InputManager::MouseRelease(int button) {

  if (InputManager::mouseUpdate[button] == InputManager::updateCounter) {
    return !(InputManager::mouseState[button]);
  } else {
    return false;
  }

}

bool InputManager::IsMouseDown(int button) {

  return InputManager::mouseState[button];

}

int InputManager::GetMouseX() {

  return InputManager::mouseX;

}

int InputManager::GetMouseY() {

  return InputManager::mouseY;

}

bool InputManager::QuitRequested() {

  return InputManager::quitRequested;

}
