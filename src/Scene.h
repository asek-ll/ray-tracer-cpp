#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>
#include <limits>
#include "RGBColor.h"
#include "Object.h"
#include "Intersection.h"
#include "Light.h"

class Scene
{
  std::vector<RGBColor> pixels;
  std::vector<std::shared_ptr<Object>> objects;
  float fov;
  Light light{Vector3(-.25f, -1, -1), RGBColor(1, 1, 1), 6};

public:
  int height, width;

  Scene(int x, int y, float foe_degree) : width(x), height(y), pixels(x * y), fov(foe_degree / 180 * 3.1415926) {}

  RGBColor &get_pixel(int, int);

  void save_image(const std::string &);

  std::optional<Intersection> trace(const Ray &ray);

  inline void add_object(std::shared_ptr<Object> object)
  {
    objects.push_back(object);
  }

  void render();
};

#endif // SCENE_H