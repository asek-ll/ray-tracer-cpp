#include "Object.h"
#include "RGBColor.h"

struct Plane : Object
{
  Vector3 origin;
  Vector3 normal;

  Plane(const Vector3 &point, const Vector3 &normal, const RGBColor &color) : origin(point), normal(normal), Object(color){};

  std::optional<float> intersect(const Ray &ray);
  Vector3 surface_normal(const Vector3 &point);
};