#include "vector3.h"
#include "RGBColor.h"

struct Light {
  Vector3 direction;
  RGBColor color;
  float intensity;
};