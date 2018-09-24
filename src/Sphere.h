#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"
#include "RGBColor.h"

struct Sphere : Object
{
  Vector3 center;
  float radius;

  Sphere(const Vector3 &center, float r, const RGBColor &color) : center(center), radius(r), Object(color){};

  std::optional<float> intersect(const Ray &ray);
  Vector3 surface_normal(const Vector3 &point);
};

#endif //SPHERE_H