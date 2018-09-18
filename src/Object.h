#ifndef OBJECT_H
#define OBJECT_H

#include <optional>
#include "Ray.h"
#include "RGBColor.h"

struct Object
{
  RGBColor color;

  Object(const RGBColor& color): color(color) {}

  virtual std::optional<float> intersect(const Ray &ray) = 0;
};

#endif // OBJECT_H