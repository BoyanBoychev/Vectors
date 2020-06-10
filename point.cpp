#include "point.h"

#include <iostream>

Point::Point() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}



//Getters
double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

double Point::getZ() {
    return this->z;
}


void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::setZ(double z) {
    this->z = z;
}


//Operators
bool operator ==(Point p1, Point p2) {
    return (p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z);
}

std::ostream& operator <<(std::ostream& out, Point p1) {
    out << '(' << p1.x << ',' << p1.y << ',' << p1.z << ')';
    return out;
}
