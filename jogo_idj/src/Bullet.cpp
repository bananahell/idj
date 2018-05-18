/**
 * @file Face.cpp
 *
 * Mechanics component of a game's object.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Bullet.h"

#include "Sprite.h"


Bullet::Bullet(GameObject& associated, float maxDistance, float angle, float speed, int damage, std::string sprite) : Component(associated) {

  Bullet::speed = Vec2(speed*Vec2::Cos(angle), speed*Vec2::Sin(angle));
  Bullet::damage = damage;
  distanceLeft = maxDistance;
  associated.rotation = angle;

  associated.AddComponent(new Sprite(associated, sprite, 3, 0.33));

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

void Bullet::Render() {

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
