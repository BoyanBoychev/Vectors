#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"point.h"


class Triangle : public Point{
public:
    Triangle(Point&, Point&, Point&);
    Triangle(double&, double&, double&);
    void sideType(Triangle&);
    void angleType(Triangle&);
    void triangleType(Triangle&);
    double Perimetar();
    double areaTriangle();
    double poluPerimetar();
    double mediCentar(Triangle&);
    double length(Point&, Point&);
    void largestSide(double,double,double);
    double maximum();

    bool operator <(Point&);
    bool operator > (Point&);
    bool operator ==(Point&);
private:
    Point firstPoint;
    Point secondPoint;
    Point thirdPoint;
    double aLen,bLen,cLen;
    double longest;
};
#endif // TRIANGLE_H
