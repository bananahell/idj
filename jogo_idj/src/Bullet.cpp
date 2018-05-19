/**
 * @file Face.cpp
 *
 * Mechanics component of a game's object.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Bullet.h"

#include "Sprite.h"
#include "Collider.h"


Bullet::Bullet(GameObject& associated,
               Sprite* sprite,
               std::string owner,
               float maxDistance,
               float angle,
               float speed,
               int damage)
       : Component(associated) {

  Bullet::owner = owner;
  Bullet::speed = Vec2(speed*Vec2::Cos(angle), speed*Vec2::Sin(angle));
  Bullet::damage = damage;
  distanceLeft = maxDistance;
  associated.rotation = angle;

  associated.AddComponent(sprite);
  associated.AddComponent(new Collider(associated));

}

Bullet::~Bullet() {

}

bool Bullet::IsOwner(std::string owner) {

  return (Bullet::owner == owner);

}

void Bullet::Update(float dt) {

  if (distanceLeft > 0) {
    associated.box.x += speed.x*dt;
    associated.box.y += speed.y*dt;
    distanceLeft -= Vec2().GetDS(Vec2(speed.x*dt, speed.y*dt));
  } else {
    associated.RequestDelete();
  }

}

void Bullet::Render(Vec2 cameraPos) {

}

bool Bullet::Is(std::string type) {

  if (type.compare("Bullet") == 0) {
    return true;
  }
  return false;

}

int Bullet::GetDamage() {

  return damage;

}
