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


Vec2::Vec2() {

  Vec2::x = 0;
  Vec2::y = 0;

}

Vec2::Vec2(float x1, float y1) : x(x1), y(y1) {


}

void Vec2::GetRandWithDistance(float distance) {

  std::random_device randomNum;
  double randomAngle =
      (2 * M_PI * (((double)randomNum()) / randomNum.max()));
  float posX, posY;

  /* Cosine = next side / hypotenuse   *
   * Sine = opposite side / hypotenuse */
  posX = (float)(cos(randomAngle) * distance);
  posY = (float)(sin(randomAngle) * distance);

  Vec2::x = posX + Vec2::x;
  Vec2::y = posY + Vec2::y;

}

Vec2 Vec2::operator+(const Vec2& rhs) const {

  return Vec2(x + rhs.x, y + rhs.y);

}

Vec2 Vec2::operator+(const float rhs) const {

  return Vec2(x + rhs, y + rhs);

}

Vec2 Vec2::operator-(const Vec2& rhs) const {

  return Vec2(x - rhs.x, y - rhs.y);

}

Vec2 Vec2::operator-(const float rhs) const {

  return Vec2(x - rhs, y - rhs);

}

Vec2 Vec2::operator*(const Vec2& rhs) const {

  return Vec2(x * rhs.x, y * rhs.y);

}

Vec2 Vec2::operator*(const float rhs) const {

  return Vec2(x * rhs, y * rhs);

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

float Vec2::GetCos(Vec2 pos) {

  return GetDX(pos.x)/GetDS(pos);

}

float Vec2::GetSin(Vec2 pos) {

  return GetDY(pos.y)/GetDS(pos);

}

float Vec2::Cos(float ang) {

  return cos(ang * M_PI/180);

}

float Vec2::Sin(float ang) {

  return sin(ang * M_PI/180);

}

float Vec2::GetAngle(Vec2 pos) {

  return atan2(GetDY(pos.y), GetDX(pos.x)) * (180/M_PI);

}
