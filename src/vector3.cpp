#include "vector3.h"

void Vector3::normalize()
{
    float len = length();
    x = x / len;
    y = y / len;
    z = z / len;
}

std::ostream &operator<<(std::ostream &os, const Vector3 &vector)
{
    os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
    return os;
}