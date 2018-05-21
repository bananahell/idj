#include "CameraFollower.h"

#include "Camera.h"


CameraFollower::CameraFollower(GameObject& associated, Vec2 truePos) : Component(associated) {

  CameraFollower::truePos = truePos;

}

CameraFollower::~CameraFollower() {


}

void CameraFollower::SetTruePos(Vec2 pos) {

  CameraFollower::truePos = pos;

}

void CameraFollower::Update(float dt) {

  CameraFollower::associated.box.SetPos(CameraFollower::truePos + Camera::pos);

}

void CameraFollower::Render() {


}

bool CameraFollower::Is(std::string type) {

  if (type.compare("CameraFollower") == 0) {
    return true;
  }
  return false;

}
