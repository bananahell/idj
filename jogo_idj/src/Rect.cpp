/**
 * @file Rect.cpp
 *
 * Game's rectangle spaces manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Rect.h"


bool Rect::Contains(float xCoord, float yCoord) {

  if (xCoord >= Rect::x &&
      yCoord >= Rect::y &&
      xCoord <= Rect::x + Rect::w &&
      yCoord <= Rect::y + Rect::h) {
    return true;
  }
  return false;

}

Vec2 Rect::GetPos() {

  return Vec2(x, y);

}

void Rect::SetCenter(Vec2 pos) {

  x = pos.x-(w/2);
  y = pos.y-(h/2);

}

void Rect::SetSize(Vec2 size) {

  w = size.x;
  h = size.y;

}

Vec2 Rect::GetSize() {

  return Vec2(w, h);

}

Vec2 Rect::GetCenter() {

  return Vec2(x + (w/2), y + (h/2));

}

void Rect::SetPos(Vec2 pos) {

  x = pos.x;
  y = pos.y;

}

void Rect::SetCenter(int x, int y) {

  Rect::x = x - Rect::w/2;
  Rect::y = y - Rect::h/2;

}
