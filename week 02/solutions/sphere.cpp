#include "sphere.h"
#include <cmath>

// Конструкцията с двоеточието означава, че преди да се влезне в тялото на
// конструктора се изпълнява присвояването center = point.
// Ако се опитаме да го направим по "стандартния" начин без да имаме конструктор
// по подразбиране за Point3D, ще получим грешка, защото в момента на влизане
// в тялото на конструктора на Sphere ще се инициализира центърът и тогава вече
// ще се извърши присвояването, но няма да има конструктор по подразбиране,
// чрез който компилаторът да извърши инициализирането на центъра.
Sphere::Sphere(Point3D const& point, double r)
    : center(point)
{
    radius = r;
}

double Sphere::volume() const {
    return 4 / 3.0 * PI * pow(radius, 3.0);
}

double Sphere::surface() const {
    return 4 * PI * radius * radius;
}

Point3D Sphere::getCenter() const {
    return center;
}

double Sphere::getRadius() const {
    return radius;
}

void Sphere::move(Point3D const& point) {
    center.setX(center.getX() + point.getX());
    center.setY(center.getY() + point.getY());
    center.setZ(center.getZ() + point.getZ());
}

bool collision(Sphere const& s1, Sphere const& s2) {
    return distance(s1.getCenter(), s2.getCenter()) <= s1.getRadius() + s2.getRadius();
}

