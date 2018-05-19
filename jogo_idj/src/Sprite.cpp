/**
 * @file Sprite.cpp
 *
 * Game's images and sprites manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Sprite.h"

#include "Game.h"
#include "Resources.h"


Sprite::Sprite(GameObject& associated) : Component(associated) {

  Sprite::texture = nullptr;
  Sprite::width = 0;
  Sprite::height = 0;
  scale = Vec2(1, 1);
  frameCount = 1;
  currentFrame = 0;
  frameTime = 1;
  timeElapsed = 0;
  loop = true;

}

Sprite::Sprite(GameObject& associated,
               std::string file,
               int frameCount,
               float frameTime,
               bool loop,
               float secondsToSelfDestruct)
       : Sprite(associated) {

  Sprite::frameCount = frameCount;
  Sprite::frameTime = frameTime;
  Sprite::loop = loop;
  Sprite::secondsToSelfDestruct = secondsToSelfDestruct;
  Open(file);

}

Sprite::~Sprite() {

  if (Sprite::texture != nullptr) {
    SDL_DestroyTexture(Sprite::texture);
  }

}

void Sprite::Open(std::string file) {

  /* Destroys previously loaded textures, if any. */
  if (Sprite::texture != nullptr) {
    SDL_DestroyTexture(Sprite::texture);
  }
  Sprite::texture = Resources::GetImage(file);
  /* Loads texture. */
  Sprite::texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(),
                                    file.c_str());

  if (SDL_QueryTexture(Sprite::texture,
                       nullptr,
                       nullptr,
                       &width,
                       &height) != 0) {
    SDL_Log("Unable to initialize Query Texture: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  /* Clips texture. */
  SetClip(0, 0, Sprite::width, Sprite::height);

}

void Sprite::SetClip(int x, int y, int w, int h) {

  Sprite::clipRect.x = x;
  Sprite::clipRect.y = y;
  Sprite::clipRect.w = w;
  Sprite::clipRect.h = h;

}

void Sprite::Render(Vec2 cameraPos) {

  Sprite::Render(Sprite::associated.box.x - cameraPos.x,
                 Sprite::associated.box.y - cameraPos.y);

}

void Sprite::Render(float x, float y) {

  SDL_Rect dstRect;
  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = Sprite::clipRect.w;
  dstRect.h = Sprite::clipRect.h;

  /* Rendering texture into Game's renderer. */
  if (SDL_RenderCopy(Game::GetInstance().GetRenderer(),
                     Sprite::texture,
                     &clipRect,
                     &dstRect) != 0) {
    SDL_Log("Unable to initialize Render Copy: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

}

int Sprite::GetWidth() {

  return (int)(width/frameCount) * scale.x;

}

int Sprite::GetHeight() {

  return Sprite::height;

}

bool Sprite::IsOpen() {

  if (Sprite::texture != nullptr) {
    return true;
  }
  return false;

}

void Sprite::Update(float dt) {

  timeElapsed += dt;
  if (secondsToSelfDestruct > 0) {
    selfDestructCount.Update(dt);
    if (selfDestructCount.Get() > secondsToSelfDestruct)
      associated.RequestDelete();
  }
  if (timeElapsed > frameTime) {
    timeElapsed -= frameTime;
    if (currentFrame < frameCount-1) {
      currentFrame += 1;
    }
    else if (loop) {
      currentFrame = 0;
    }
    SetClip(currentFrame*(width/frameCount), 0, (width/frameCount), height);
  }

}

bool Sprite::Is(std::string type) {

  if (type.compare("Sprite") == 0) {
    return true;
  }
  return false;

}

void Sprite::SetScale(Vec2 scale) {

  Sprite::scale = scale;
  associated.box.w = GetWidth();
  associated.box.h = GetHeight();

}

void Sprite::SetFrame(int frame) {

  currentFrame = frame;

}

void Sprite::SetFrameCount(int frameCount) {

  Sprite::frameCount = frameCount;

}

void Sprite::SetFrameTime(float frameTime) {

  Sprite::frameTime = frameTime;

}
