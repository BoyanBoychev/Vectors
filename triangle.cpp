#include "triangle.h"
#include "exceptions.h"
#include <cmath>

Triangle::Triangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint){
    if(firstPoint.getX() == secondPoint.getX() && firstPoint.getY() == secondPoint.getY()) throw EqualPointException(1,2);
    if(firstPoint.getX() == thirdPoint.getX() && firstPoint.getY() == thirdPoint.getY()) throw EqualPointException(1,3);
    if(secondPoint.getX() == thirdPoint.getX() && secondPoint.getY() == thirdPoint.getY()) throw EqualPointException(2,3);

    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->thirdPoint = thirdPoint;
}

bool Triangle::checkTriangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    if(firstPoint.getX + secondPoint.getY > ThirdPoint.getZ && ThirdPoint.getZ + secondPoint.getY > firstPoint.getX &&
       firstPoint.getX + ThirdPoint.getZ > secondPoint.getY)
        return true;
    else return false;
}

double Triangle::poluPerimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return(firstPoint.getX + secondPoint.getY + ThirdPoint.getZ)/2;
}

void Triangle::checkTriangleTyper(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{

    if(!checkTriangle()){
            ///exception throw трябва да има тук !
        cout<<"Not a valid triangle"<<endl;
    } else{
        if(firstPoint.getX == secondPoint.getY && secondPoint.getY == ThirdPoint.getZ)
            cout<<"Ravnostranen"<<endl;
        else if(firstPoint.getX == secondPoint.getY || secondPoint.getY == ThirdPoint.getZ ||
                ThirdPoint.getZ == firstPoint.getX)
                    cout<<"Ravnobedren"<<endl;
        else
            cout<<"Raznostranen"<<endl;
    }

    unsigned longest = ThirdPoint.getZ;
    if(longest < firstPoint.getX){
        ThirdPoint.getZ = longest;
        longest = firstPoint.getX;
        firstPoint.getX = ThirdPoint.getZ;
    }
    if(longest < secondPoint.getY){
        ThirdPoint.getZ = longest;
        longest = secondPoint.getY;
        secondPoint.getY = ThirdPoint.getZ;
    }

    if(firstPoint.getX*firstPoint.getX + secondPoint.getY*secondPoint.getY == longest*longest){
        cout<<"Pravougulen"<<endl;
    } else if(firstPoint.getX*firstPoint.getX + secondPoint.getY*secondPoint.getY >longest*longest)
    {
        cout <<"Ostrougulen"<<endl;
    } else{cout<<"Tupougulen"<<endl;}
}

double Triangle::areaTriangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    double p = poluPerimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint);

    ///херонова формула.
    return sqrt(p*(p-firstPoint.getX)*(p-secondPoint.getY)*(p-ThirdPoint.getZ));
}

double Triangle::perimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return (firstPoint.getX + secondPoint.getY + ThirdPoint.getZ);
}

double Triangle::mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return(sqrt(2*(ThirdPoint.getZ*ThirdPoint.getZ)+2*(secondPoint.getY*secondPoint.getY)-
                (firstPoint.getX*firstPoint.getX))/2);
}
double Triangle::mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return (sqrt(2*(ThirdPoint.getZ*ThirdPoint.getZ)+2*(firstPoint.getX*firstPoint.getX)-
                 (secondPoint.getY*secondPoint.getY))/2);
}
double Triangle::mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return(sqrt(2*(firstPoint.getX*firstPoint.getX)+2*(secondPoint.getY*secondPoint.getY)-
                (ThirdPoint.getZ*ThirdPoint.getZ))/2);
}

double Triangle::mediCentar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{

    return((mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint))/3);

}

