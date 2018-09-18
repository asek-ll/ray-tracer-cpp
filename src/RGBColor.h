#ifndef RGB_COLOR_H
#define RGB_COLOR_H

struct RGBColor
{
  unsigned char r;
  unsigned char g;
  unsigned char b;

  RGBColor() : RGBColor(0, 0, 0) {}
  RGBColor(char r, char g, char b) : r(r), g(g), b(b) {}
};

#endif //RGB_COLOR_H