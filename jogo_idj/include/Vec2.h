#ifndef VEC2_H
#define VEC2_H


class Vec2 {

 public:

  Vec2();
  Vec2(float x, float y);
  ~Vec2();

  Vec2 operator+(const Vec2& rhs) const;
  Vec2 operator+(const float rhs) const;
  Vec2 operator-(const Vec2& rhs) const;
  Vec2 operator-(const float rhs) const;
  Vec2 operator*(const Vec2& rhs) const;
  Vec2 operator*(const float rhs) const;
  Vec2 operator/(const Vec2& rhs) const;
  Vec2 operator/(const float rhs) const;

  Vec2 Rotate(float ang);
  float GetDX(float x);
  float GetDY(float y);
  float GetDS(Vec2 pos);
  float GetCos(Vec2 pos);
  float GetSin(Vec2 pos);
  float GetAngle(Vec2 pos);
  static float Cos(float ang);
  static float Sin(float ang);
  static Vec2 Project(float dist, float ang);

  float x;
  float y;

};
#endif /* VEC2_H */
