/**
 * @file Rect.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Rect.h"


Rect::Rect() {

  Rect::w = 0;
  Rect::h = 0;
  Rect::x = 0;
  Rect::y = 0;

}

Rect::Rect(float w, float h) {

  Rect::w = w;
  Rect::h = h;
  Rect::x = 0;
  Rect::y = 0;

}
