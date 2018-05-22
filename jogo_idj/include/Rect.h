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

  Rect();
  Rect(float x, float y, float w, float h);
  ~Rect();

  void SetPos(float x, float y);
  void SetPos(Vec2 pos);
  void SetSize(float w, float h);
  void SetSize(Vec2 size);
  void SetCenter(float x, float y);
  void SetCenter(Vec2 center);
  bool Contains(float a, float b);
  bool Contains(Vec2 p);
  Vec2 GetPos();
  Vec2 GetSize();
  Vec2 GetCenter();

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
