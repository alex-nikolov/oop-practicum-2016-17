#include <iostream>

#include "sphere.h"
#include "cube.h"

using namespace std;

int main() {
    Point3D p(1, 2, 3.5);
    Point3D q(2, 4, 2);
    cout << distance(p, q) << endl;

    Sphere s1(p, 2);
    Sphere s2(q, 0.7);
    cout << collision(s1, s2) << endl;

    // По този начин можем да си създадем временен обект точка,
    // който след като приключи изпълнението на move се унищожава.
    s2.move(Point3D(1, 0, 0));
    cout << collision(s1, s2) << endl;

    Cube c1(Point3D(1, 2, 3), 2);
    Cube c2(Point3D(3, 4, 5), 1.95);
    cout << collision(c1, c2) << endl;

    c2.move(Point3D(-0.2, -0.2, -0.2));
    cout << collision(c1, c2) << endl;
}
