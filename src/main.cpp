#include "vector3.h"
#include "Scene.h"
#include "Sphere.h"
#include <memory>
#include "Plane.h"
#include "Vector3.h"
#include "RGBColor.h"

int main()
{
  Scene test(800, 600, 120);

  test.add_object(std::make_shared<Sphere>(Vector3(2, 2, -5), 1, RGBColor(255, 0, 0)));
  test.add_object(std::make_shared<Sphere>(Vector3(-2, -2, -5), 2, RGBColor(0, 255, 0)));
  test.add_object(std::make_shared<Plane>(Vector3(0, 1.5, 0), Vector3(0, 1, 0), RGBColor(0, 0, 255)));
  test.add_object(std::make_shared<Plane>(Vector3(0, -2.5, 0), Vector3(0, -1, 0), RGBColor(128, 0, 255)));

  test.render();

  test.save_image("out.bmp");
}
