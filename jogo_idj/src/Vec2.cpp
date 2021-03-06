#define PI 3.141592653589793

#include "Vec2.h"

#include <cmath>


Vec2::Vec2() {

  Vec2::x = 0;
  Vec2::y = 0;

}

Vec2::Vec2(float x, float y) {

  Vec2::x = x;
  Vec2::y = y;

}

Vec2::~Vec2() {


}

Vec2 Vec2::operator+(const Vec2& rhs) const {

  return Vec2(Vec2::x + rhs.x, Vec2::y + rhs.y);

}

Vec2 Vec2::operator+(const float rhs) const {

  return Vec2(Vec2::x + rhs, Vec2::y + rhs);

}

Vec2 Vec2::operator-(const Vec2& rhs) const {

  return Vec2(Vec2::x - rhs.x, Vec2::y - rhs.y);

}

Vec2 Vec2::operator-(const float rhs) const {

  return Vec2(Vec2::x - rhs, Vec2::y - rhs);

}

Vec2 Vec2::operator*(const Vec2& rhs) const {

  return Vec2(Vec2::x * rhs.x, Vec2::y * rhs.y);

}

Vec2 Vec2::operator*(const float rhs) const {

  return Vec2(Vec2::x * rhs, Vec2::y * rhs);

}

Vec2 Vec2::operator/(const Vec2& rhs) const {

  return Vec2(Vec2::x / rhs.x, Vec2::y / rhs.y);

}

Vec2 Vec2::operator/(const float rhs) const {

  return Vec2(Vec2::x / rhs, Vec2::y / rhs);

}

Vec2 Vec2::Rotate(float ang) {

  return Vec2(Vec2::x * Cos(ang) - Vec2::y * Sin(ang), Vec2::y * Cos(ang) + Vec2::x * Sin(ang));

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

float Vec2::GetAngle(Vec2 pos) {

  return atan2(GetDY(pos.y), GetDX(pos.x)) * (180/PI);

}

float Vec2::Cos(float ang) {

  return cos(ang * PI/180);

}

float Vec2::Sin(float ang) {

  return sin(ang * PI/180);

}

Vec2 Vec2::Project(float dist, float ang) {

  return Vec2(Cos(ang) * dist, Sin(ang) * dist);

}
