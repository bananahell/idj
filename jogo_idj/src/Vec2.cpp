/**
 * @file Vec2.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Vec2.h"

#include <random>

#include <cmath>


Vec2::Vec2(float x1, float y1) : x(x1), y(y1) {


}

void Vec2::GetRandWithDistance(int distance) {

  std::random_device randomNum;
  double randomAngle = (2 * (((double)randomNum()) / randomNum.max())) - 1;
  int posX, posY;

  posX = (int)(cos(randomAngle) * distance);
  if (Vec2::x < abs(posX)) {
    GetRandWithDistance(distance);
  } else {
    Vec2::x = (float)posX;
    posY = (int)(sin(randomAngle) * distance);
    if ((int)((((double)randomNum()) / randomNum.max()) * 2) == 1) {
      if (Vec2::y < abs(posY)) {
        posY *= -1;
        Vec2::y = (float)posY;
      }
    } else {
      posY *= -1;
      if (Vec2::y < abs(posY)) {
        posY *= -1;
        Vec2::y = (float)posY;
      }
    }
  }

}

float Vec2::GetDX(float x) {

  return x - Vec2::x;

}

float Vec2::GetDY(float y) {

  return y - Vec2::y;

}

float Vec2::GetDS(Vec2 pos) {

  return pow(pow(GetDX(pos.x), 2) + pow(GetDY(pos.y), 2), 0.5);

}

Vec2 Vec2::operator+(const Vec2& rhs) const {

  return Vec2(x + rhs.x, y + rhs.y);

}

Vec2 Vec2::operator-(const Vec2& rhs) const {

  return Vec2(x - rhs.x, y - rhs.y);

}

Vec2 Vec2::operator*(const float rhs) const {

  return Vec2(x * rhs, y * rhs);

}

float Vec2::Cos(float ang) {

  return cos(ang * PI / 180);

}

float Vec2::Sin(float ang) {

  return sin(ang * PI / 180);

}

Vec2 Vec2::Project(float dist, float ang) {

  return Vec2(Cos(ang) * dist, Sin(ang) * dist);

}
