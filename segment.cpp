#include "segment.h"

Segment::Segment() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Segment::Segment(Point& pt1, Vector& vect1, double t){
    if (t < 0 || t > 1){
        throw EXCEPTT();
    }

    this->x = pt1.getX() + vect1.getX() * t;
    this->y = pt1.getY() + vect1.getY() * t;
    this->z = pt1.getZ() + vect1.getZ() * t;
    cout << "Segment: " << x << "\t" << y << "\t" << z << "\t" << endl;
}

unsigned Segment::segLen(){
    return sqrt(pow((Vector::getZ() - Point::getZ()),2)
    +pow((Vector::getX() - Point::getX()),2)
    +pow((Vector::getY() - Point::getY()),2));
}

unsigned Segment::lenSeg(Vector& vect2,Point& pt2){
    return sqrt(pow((pt2.getZ() - vect2.getZ()),2)
    +pow((pt2.getX() - vect2.getX()),2)
    +pow((pt2.getY() - vect2.getY()),2));
}

Point Segment::segMid(Vector& vect3 ,Point& pt3){
    Point ptMid;
    ptMid.setX((pt3.getX() + vect3.getX())/2);
    ptMid.setY((pt3.getY() + vect3.getY())/2);
    ptMid.setZ((pt3.getZ() + vect3.getZ())/2);

    return ptMid;
}
