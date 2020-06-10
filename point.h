#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#define PI 3.14159265359
using namespace std;

class Point
{
protected:
    double x, y, z;
public:

    Point();
    Point(double, double, double);

    //Getters
    double getX();
    double getY();
    double getZ();

    void setX(double);
    void setY(double);
    void setZ(double);

    friend bool operator ==(Point, Point);
    friend std::ostream& operator <<(std::ostream&, Point);
};
#endif // POINT_H
