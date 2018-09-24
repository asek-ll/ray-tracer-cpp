#include "Plane.h"

std::optional<float> Plane::intersect(const Ray &ray)
{
  auto denom = normal.dot(ray.direction);
  if (denom > 1e-6)
  {
    auto v = origin - ray.origin;
    auto distance = v.dot(normal) / denom;
    if (distance >= 0)
    {
      return distance;
    }
  }
  return {};
}

Vector3 Plane::surface_normal(const Vector3 &point)
{
  return -normal;
}