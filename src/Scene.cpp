#include "Scene.h"
#include <math.h>
#include <iostream>

RGBColor &Scene::get_pixel(int x, int y)
{
  return pixels[y * width + x];
}

void Scene::save_image(const std::string &fileName)
{
  const int image_size = height * width * 4;
  const int headers_size = 14 + 40;
  const int filesize = image_size + headers_size;
  const int pixelsPerMeter = 2835;

  unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
  //size of the file in bytes
  bmpfileheader[2] = (unsigned char)(filesize);
  bmpfileheader[3] = (unsigned char)(filesize >> 8);
  bmpfileheader[4] = (unsigned char)(filesize >> 16);
  bmpfileheader[5] = (unsigned char)(filesize >> 24);

  unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
  //width of the image in bytes
  bmpinfoheader[4] = (unsigned char)(width);
  bmpinfoheader[5] = (unsigned char)(width >> 8);
  bmpinfoheader[6] = (unsigned char)(width >> 16);
  bmpinfoheader[7] = (unsigned char)(width >> 24);

  //height of the image in bytes
  bmpinfoheader[8] = (unsigned char)(height);
  bmpinfoheader[9] = (unsigned char)(height >> 8);
  bmpinfoheader[10] = (unsigned char)(height >> 16);
  bmpinfoheader[11] = (unsigned char)(height >> 24);

  // Size image in bytes
  bmpinfoheader[21] = (unsigned char)(image_size);
  bmpinfoheader[22] = (unsigned char)(image_size >> 8);
  bmpinfoheader[23] = (unsigned char)(image_size >> 16);
  bmpinfoheader[24] = (unsigned char)(image_size >> 24);

  bmpinfoheader[25] = (unsigned char)(pixelsPerMeter);
  bmpinfoheader[26] = (unsigned char)(pixelsPerMeter >> 8);
  bmpinfoheader[27] = (unsigned char)(pixelsPerMeter >> 16);
  bmpinfoheader[28] = (unsigned char)(pixelsPerMeter >> 24);

  bmpinfoheader[29] = (unsigned char)(pixelsPerMeter);
  bmpinfoheader[30] = (unsigned char)(pixelsPerMeter >> 8);
  bmpinfoheader[31] = (unsigned char)(pixelsPerMeter >> 16);
  bmpinfoheader[32] = (unsigned char)(pixelsPerMeter >> 24);

  FILE *file = fopen(fileName.c_str(), "wb"); //write-binary

  fwrite(bmpfileheader, 1, 14, file);
  fwrite(bmpinfoheader, 1, 40, file);

  for (int i = 0; i < pixels.size(); ++i)
  {
    const RGBColor pixel = pixels[i];
    unsigned char color[3] = {
        pixel.b * 255,
        pixel.g * 255,
        pixel.r * 255};
    fwrite(color, 1, 3, file);
  }
  fclose(file);
};

std::optional<Intersection> Scene::trace(const Ray &ray)
{
  float minDist = 0;
  std::shared_ptr<Object> closestObject(nullptr);
  for (auto const &object : objects)
  {
    auto inter = object->intersect(ray);
    if (inter.has_value() && (!closestObject || minDist > *inter))
    {
      minDist = *inter;
      closestObject = object;
    }
  }
  if (closestObject)
  {
    return Intersection(minDist, closestObject);
  }
  return {};
}

void Scene::render()
{
  for (int i = 0; i < width * height; ++i)
  {
    int x = i % width;
    int y = i / width;

    auto pixel = &get_pixel(x, y);

    auto fov_adjustment = tan(fov / 2);
    auto aspect_ration = (float)width / height;

    auto sensor_x = ((x + 0.5) / width * 2 - 1) * aspect_ration * fov_adjustment;
    auto sensor_y = ( ((y + 0.5) / height * 2) - 1) * fov_adjustment;

    Ray ray(sensor_x, sensor_y, -1);

    auto interseciton = trace(ray);
    if (interseciton)
    {
      auto hit_point = ray.origin + (ray.direction * interseciton->distance);
      auto surface_normal = interseciton->element->surface_normal(hit_point);
      auto direction_to_light = -light.direction;
      auto light_power = std::max(surface_normal.dot(direction_to_light), 0.f) * light.intensity;
      // std::cout << "power " << light_power << " normal " << surface_normal << std::endl;
      auto light_reflected = 1 / 3.1415;

      auto color = interseciton->element->color * light.color * light_power * light_reflected;
      color.clamp();

      pixel->r = color.r;
      pixel->g = color.g;
      pixel->b = color.b;
    }
    else
    {
      pixel->r = 1;
      pixel->g = 1;
      pixel->b = 1;
    }
  }
}