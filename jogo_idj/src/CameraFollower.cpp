/**
 * @file CameraFollower.cpp
 *
 * Mechanics component of a game's object.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "CameraFollower.h"
#include "Camera.h"


CameraFollower::CameraFollower(GameObject& associated) : Component(associated) {


}

void CameraFollower::Update(float dt) {

  CameraFollower::associated.box.x = Camera::pos.x;
  CameraFollower::associated.box.y = Camera::pos.y;

}

void CameraFollower::Render(Vec2 cameraPos) {


}

bool CameraFollower::Is(std::string type) {

  if (type.compare("CameraFollower") == 0) {
    return true;
  }
  return false;

}
