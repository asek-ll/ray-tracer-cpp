#ifndef RGB_COLOR_H
#define RGB_COLOR_H

#include <math.h>

struct RGBColor
{
  float r;
  float g;
  float b;

  RGBColor() : RGBColor(0, 0, 0) {}
  RGBColor(float r, float g, float b) : r(r), g(g), b(b) {}

  inline RGBColor operator*(const RGBColor &color)
  {
    return RGBColor(color.r * r, color.g * g, color.b * b);
  }

  inline RGBColor operator*(float factor)
  {
    return RGBColor(factor * r, factor * g, factor * b);
  }

  inline void clamp()
  {
    r = std::max(std::min(r, 1.f), 0.f);
    g = std::max(std::min(g, 1.f), 0.f);
    b = std::max(std::min(b, 1.f), 0.f);
  }
};

#endif //RGB_COLOR_H