#include "Sprite.h"

#include "Camera.h"
#include "Game.h"
#include "Resources.h"


Sprite::Sprite(GameObject& associated) : Component(associated) {

  Sprite::texture = nullptr;
  Sprite::width = 0;
  Sprite::height = 0;
  Sprite::scale = Vec2(1, 1);
  Sprite::frameCount = 1;
  Sprite::currentFrame = 0;
  Sprite::frameTime = 1;
  Sprite::timeElapsed = 0;
  Sprite::loop = true;

}

Sprite::Sprite(GameObject& associated, std::string file, int frameCount, float frameTime, bool loop, float secondsToSelfDestruct) : Sprite(associated) {

  Sprite::frameCount = frameCount;
  Sprite::frameTime = frameTime;
  Sprite::loop = loop;
  Sprite::secondsToSelfDestruct = secondsToSelfDestruct;
  Open(file);

}

Sprite::~Sprite() {

  Sprite::texture = nullptr;

}

void Sprite::Open(std::string file) {

  Sprite::texture = Resources::GetImage(file);
  SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height);
  SetClip(0, 0, (width/frameCount), height);
  Sprite::associated.box.w = GetWidth();
  Sprite::associated.box.h = GetHeight();

}

void Sprite::SetClip(int x, int y, int w, int h) {

  Sprite::clipRect.x = x;
  Sprite::clipRect.y = y;
  Sprite::clipRect.w = w;
  Sprite::clipRect.h = h;

}

void Sprite::SetScale(Vec2 scale) {

  Sprite::scale = scale;
  Sprite::associated.box.w = GetWidth();
  Sprite::associated.box.h = GetHeight();

}

void Sprite::SetFrame(int frame) {

  Sprite::currentFrame = frame;

}

void Sprite::SetFrameCount(int frameCount) {

  Sprite::frameCount = frameCount;

}

void Sprite::SetFrameTime(float frameTime) {

  Sprite::frameTime = frameTime;

}

void Sprite::Update(float dt) {

  Sprite::timeElapsed += dt;
  if (Sprite::secondsToSelfDestruct > 0) {
    Sprite::selfDestructCount.Update(dt);
    if (Sprite::selfDestructCount.Get() > Sprite::secondsToSelfDestruct) {
      Sprite::associated.RequestDelete();
    }
  }
  if (Sprite::timeElapsed > Sprite::frameTime) {
    Sprite::timeElapsed -= Sprite::frameTime;
    if (Sprite::currentFrame < Sprite::frameCount - 1) {
      Sprite::currentFrame += 1;
    } else if (loop) {
      Sprite::currentFrame = 0;
    }
    SetClip(Sprite::currentFrame*(Sprite::width/Sprite::frameCount), 0, (Sprite::width/Sprite::frameCount), Sprite::height);
  }

}

void Sprite::Render() {

  Render(Sprite::associated.box.x-Camera::pos.x, Sprite::associated.box.y-Camera::pos.y);

}

void Sprite::Render(int x, int y) {

  SDL_Rect dstRect;
  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = (int)clipRect.w*scale.x;
  dstRect.h = (int)clipRect.h*scale.y;
  SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), Sprite::texture.get(), &clipRect, &dstRect, Sprite::associated.rotation, nullptr, SDL_FLIP_NONE);

}

bool Sprite::Is(std::string type) {

  if (type.compare("Sprite") == 0) {
    return true;
  }
  return false;

}

int Sprite::GetWidth() {

  return (int)(Sprite::width/Sprite::frameCount)*Sprite::scale.x;

}

int Sprite::GetHeight() {

  return (int)Sprite::height*Sprite::scale.y;

}

Vec2 Sprite::GetScale() {

  return scale;

}

bool Sprite::IsOpen() {

  if (Sprite::texture == nullptr) {
    return false;
  }
  return true;

}
