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

void Vec2::GetRandWithDistance(float distance) {

  std::random_device randomNum;
  double randomAngle = (2 * Vec2::PI * (((double)randomNum()) / randomNum.max()));
  float posX, posY;

  posX = (float)(cos(randomAngle) * distance);
  posY = (float)(sin(randomAngle) * distance);

  Vec2::x = posX + Vec2::x;
  Vec2::y = posY + Vec2::y;

}
