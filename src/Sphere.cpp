#include "Sphere.h"

std::optional<float> Sphere::intersect(const Ray &ray)
{
  auto l = center - ray.origin;

  auto adj = l.dot(ray.direction);
  auto d2 = l.dot(l) - (adj * adj);

  auto radius2 = radius * radius;

  if (d2 > radius2)
  {
    return {};
  }

  auto thc = sqrt(radius2 - d2);

  auto t0 = adj - thc;
  auto t1 = adj + thc;

  if (t0 < 0 && t1 < 0)
  {
    return {};
  }

  if (t0 < t1)
  {
    return t0;
  }

  return t1;
}

Vector3 Sphere::surface_normal(const Vector3 &point)
{
  auto result = point - center;
  result.normalize();
  return result;
}
