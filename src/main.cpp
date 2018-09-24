#include "vector3.h"
#include "Scene.h"
#include "Sphere.h"
#include <memory>
#include "Plane.h"
#include "Vector3.h"
#include "RGBColor.h"

int main()
{
  Scene test(800, 600, 90);

  test.add_object(std::make_shared<Sphere>(Vector3(0, 0, -5), 1, RGBColor(.2, 1, .2)));
  test.add_object(std::make_shared<Sphere>(Vector3(-3, 1, -6), 2, RGBColor(.2, .2, 1)));
  test.add_object(std::make_shared<Sphere>(Vector3(2, 2, -4), 1.5, RGBColor(1, .2, .2)));
  test.add_object(std::make_shared<Plane>(Vector3(0, -2, 0), Vector3(0, -1, 0), RGBColor(.2, .2, .2)));
  test.add_object(std::make_shared<Plane>(Vector3(0, 0, -20), Vector3(0, 0, -1), RGBColor(.6f, .8f, 1)));

  test.render();

  test.save_image("out.bmp");
}
