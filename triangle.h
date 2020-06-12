#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"point.h"
#include <cmath>

class Triangle : public Point{
public:
    Triangle(Point&, Point&, Point&);
    void checkTriangleType(Point&, Point&, Point&);
    double poluPerimetar(Point&, Point&, Point&);
    double areaTriangle(Point&, Point&, Point&);
    double perimetar(Point&, Point&, Point&);
    double mX(Point&, Point&, Point&);
    double mY(Point&, Point&, Point&);
    double mZ(Point&, Point&, Point&);
    double mediCentar(Point&, Point&, Point&);

private:
    Point firstPoint;
    Point secondPoint;
    Point thirdPoint;
    unsigned longest;
};
#endif // TRIANGLE_H
