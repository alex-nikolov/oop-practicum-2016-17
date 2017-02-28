#ifndef SPHERE_H
#define SPHERE_H

#include "point3d.h"

const double PI = 3.14;

class Sphere {
    Point3D center;
    double radius;
public:
    Sphere(Point3D const&, double);

    double volume() const;
    double surface() const;
    void move(Point3D const&);

    Point3D getCenter() const;
    double getRadius() const;
};

bool collision(Sphere const&, Sphere const&);

#endif // SPHERE_H
