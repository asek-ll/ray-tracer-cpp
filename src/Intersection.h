
#include <memory>
#include "Object.h"

struct Intersection
{
  float distance;
  std::shared_ptr<Object> element;

  Intersection(float distance, std::shared_ptr<Object> element) : distance(distance), element(element) {}
};