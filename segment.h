#ifndef SEGMENT_H
#define SEGMENT_H
#include "Line.h"

class Segment:public Line{
private:
    Point pt;
    Vector Vect;
    double t;
    double x,y,z;


public:
    Segment();
    Segment(Point&, Vector&, double);
    unsigned segLen();
    unsigned lenSeg(Vector&, Point&);
    Point segMid(Vector&, Point&);
};

#endif // SEGMENT_H
