#ifndef POINT_3D_H
#define POINT_3D_H

class Point3D {
    double x;
    double y;
    double z;
public:
    Point3D(double, double, double);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double);
    void setY(double);
    void setZ(double);
};

double distance(Point3D const&, Point3D const&);

#endif // POINT_3D_H
