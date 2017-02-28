#ifndef CUBE_H
#define CUBE_H

#include "point3d.h"

class Cube {
    Point3D center;
    double edge;
public:
    Cube(Point3D const&, double);

    double volume() const;
    double surface() const;
    void move(Point3D const&);

    Point3D getCenter() const;
    double getEdge() const;
};

bool collision(Cube const&, Cube const&);

#endif // Cube_H
