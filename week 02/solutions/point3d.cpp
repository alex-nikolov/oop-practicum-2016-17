#include "point3d.h"
#include <cmath>

Point3D::Point3D(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
}

double Point3D::getX() const {
    return x;
}

double Point3D::getY() const {
    return y;
}

double Point3D::getZ() const {
    return z;
}

void Point3D::setX(double newX) {
    x = newX;
}

void Point3D::setY(double newY) {
    y = newY;
}

void Point3D::setZ(double newZ) {
    z = newZ;
}

double distance(Point3D const& p1, Point3D const& p2) {
    return sqrt(pow(p1.getX() - p2.getX(), 2.0) +
                pow(p1.getY() - p2.getY(), 2.0) +
                pow(p1.getZ() - p2.getZ(), 2.0));
}
