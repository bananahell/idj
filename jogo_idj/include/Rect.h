/**
 * @file Rect.h
 *
 * Rect's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef RECT_H
#define RECT_H

#include "Vec2.h"


/**
 * Rect class. Class containing information needed to place a game object in the
 * game's window, like coordinates and size.
 */
class Rect {

 public:

  /**
   * Function used to find if a given point is inside this rectangle's area.
   *
   * @param xCoord - Horizontal coordinate of the given point.
   * @param yCoord - Vertical coordinate of the given point.
   *
   * @return True if the point (xCoord, yCoord) is inside the rectangle's area.
   */
  bool Contains(float xCoord, float yCoord);
  Vec2 GetPos();
	Vec2 GetCenter();
	void SetPos(Vec2 pos);

  /**
   * Horizontal coordinate of the left-top most point of the rectangle.
   */
  float x;
  /**
   * Vertical coordinate of the left-top most point of the rectangle.
   */
  float y;
  /**
   * Rectangle's width.
   */
  float w;
  /**
   * Rectangle's height.
   */
  float h;

};
#endif /* RECT_H */
