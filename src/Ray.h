#ifndef RAY_H
#define RAY_H

#include "vector3.h"

struct Ray
{
  Vector3 origin, direction;

  Ray(float x, float y, float z) : direction(x, y, z)
  {
    direction.normalize();
  }
};

#endif // RAY_H