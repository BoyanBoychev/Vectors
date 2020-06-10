#ifndef LINE_H
#define LINE_H
#include "point.h"
#include "vector.h"

class Line:public Vector{
private:
    Point p1;
    Point p2;
public:
    Line();
    Point LineStart();
    Point LineEnd();
    Line (Point , Vector );
    Line (Point& , Point& );
    double lenght(Point&, Point&);
    Vector getDirection(Point&, Point&);
    ///Vector normalVector(Line&, Point&);
    Line operator +(Point&,Point&,Point&,Point&,Point&,Point&);


    //getters
    double getX() {
          return this->x;
      }

    double getY() {
          return this->y;
      }

    double getZ() {
          return this->z;
      }


};

#endif // LINE_H
