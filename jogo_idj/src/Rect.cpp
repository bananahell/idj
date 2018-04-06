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
