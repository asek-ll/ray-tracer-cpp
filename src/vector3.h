#ifndef VECTOR_3_H
#define VECTOR_3_H

#include <cmath>
#include <ostream>

struct Vector3
{
  float x, y, z;
  inline Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

  inline Vector3 operator+(const Vector3 &a) const
  {
    return Vector3(x + a.x, y + a.y, z + a.z);
  }
  inline Vector3 operator-(const Vector3 &a) const
  {
    return Vector3(x - a.x, y - a.y, z - a.z);
  }

  inline Vector3 operator-() const
  {
    return Vector3(-x, -y, -z);
  }

  inline Vector3 operator*(float factor) const
  {
    return Vector3(x * factor, y * factor, z * factor);
  }

  inline float dot(const Vector3 &a) const
  {
    return x * a.x + y * a.y + z * a.z;
  }

  inline float length()
  {
    return sqrt(x * x + y * y + z * z);
  }

  void normalize();
  friend std::ostream &operator<<(std::ostream &, const Vector3 &);
};

#endif // VECTOR3_H
