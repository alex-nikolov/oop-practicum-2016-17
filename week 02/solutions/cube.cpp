#include "cube.h"
#include <cmath>

using namespace std;

Cube::Cube(Point3D const& point, double e)
    : center(point)
{
    edge = e;
}

double Cube::volume() const {
    return pow(edge, 3.0);
}

double Cube::surface() const {
    return 6 * edge * edge;
}

Point3D Cube::getCenter() const {
    return center;
}

double Cube::getEdge() const {
    return edge;
}

void Cube::move(Point3D const& point) {
    center.setX(center.getX() + point.getX());
    center.setY(center.getY() + point.getY());
    center.setZ(center.getZ() + point.getZ());
}

bool collision(Cube const& c1, Cube const& c2) {
    Point3D p1 = c1.getCenter();
    Point3D p2 = c2.getCenter();

    double halfEdgeSum = c1.getEdge() / 2.0 + c2.getEdge() / 2.0;

    bool overlapX = abs(p1.getX() - p2.getX()) <= halfEdgeSum;
    bool overlapY = abs(p1.getY() - p2.getY()) <= halfEdgeSum;
    bool overlapZ = abs(p1.getZ() - p2.getZ()) <= halfEdgeSum;

    return overlapX && overlapY && overlapZ;
}


