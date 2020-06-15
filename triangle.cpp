#include "triangle.h"
#include "exceptions.h"
#include <cmath>

//d = ((x2 - x1)2 + (y2 - y1)2 + (z2 - z1)2)1/2

double Triangle::length(Point& p1, Point& p2){
    return pow(pow(p2.getX() - p1.getX(),2) + pow(p2.getY() - p1.getY(),2) + pow(p2.getZ() - p1.getZ(),2),0.5);
   }


Triangle::Triangle(Point& firstPoint, Point& secondPoint, Point& thirdPoint){
    if(firstPoint.getX() == secondPoint.getX() && firstPoint.getY() == secondPoint.getZ()) throw EPE(1,2);
    if(firstPoint.getX() == thirdPoint.getX() && firstPoint.getY() == thirdPoint.getZ()) throw EPE(1,3);
    if(secondPoint.getX() == thirdPoint.getX() && secondPoint.getY() == thirdPoint.getZ()) throw EPE(2,3);
    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->thirdPoint = thirdPoint;
    cout <<"Triangle with Points:  " << firstPoint << ',' << secondPoint << ',' << thirdPoint << endl;
    aLen = length(this->secondPoint, this->thirdPoint);
    bLen = length(this->firstPoint, this->thirdPoint);
    cLen = length(this->firstPoint, this->secondPoint);
}

double Triangle::maximum() {
    Triangle& t1 = *this;
    double max = t1.aLen;

    if (t1.bLen > max) {
        max = t1.bLen;
}
    if (t1.cLen > max) {
        max = t1.cLen;
}
    return max;
}

double Triangle::Perimetar()
{

    return(aLen + bLen + cLen);
}

double Triangle::poluPerimetar()
{
    Triangle& t1 = *this;
    return (t1.Perimetar())/2;
}

double Triangle::areaTriangle()
{
    Triangle& t1 = *this;
    double p = t1.poluPerimetar();
    return sqrt(p*(p-aLen)*(p-bLen)*(p-cLen));
}

void Triangle::sideType(Triangle&, t1)
{
    Triangle& t1 = *this;

    if(aLen == bLen && bLen==cLen)
    {
        cout<<"Ravnostranen\n";
    }
    else if(aLen==bLen || aLen==cLen || bLen==cLen)
    {
        cout<<"Ravnobedren\n";
    }
    else{
        cout<<"Raznostranen\n";
    }
}

void Triangle::angleType(Triangle& t1)
{
    Triangle& t1 = *this;

    if(aLen + bLen > cLen)
    {
        cout <<"Ostrougulen\n";
    }
    else if(pow(aLen,2)+pow(bLen,2) == pow(cLen,2))
    {
        cout<<"Pravougulen\n";
    }
    else{
        cout<<"Tupougulen\n";
    }

}

void Triangle::triangleType(Triangle& t1)
{
    Triangle& t1 = *this;

    cout<<"Triugulnikut e: "<<sideType(Triangle& t1)<<" i "<<angleType(Triangle& t1)<<endl;

}

double Triangle::mediCentar(Triangle& t1)
{
    double a = (firstPoint.getX()+ secondPoint.getX() + thirdPoint.getX())/3;
    double b = (firstPoint.getY() + secondPoint.getY() + thirdPoint.getY())/3;
    double c = (firstPoint.getZ() + secondPoint.getZ() + thirdPoint.getZ())/3;

    return Point(a,b,c);
}

bool Triangle::operator <(Point& p)
{
    double A = ((secondPoint.getY() - thirdPoint.getY())*(p.getX()-thirdPoint.getX())+(thirdPoint.getX() - secondPoint.getX())*
                (p.getY()-thirdPoint.getY())/(secondPoint.getY()-thirdPoint.getY())*(firstPoint.getX()-thirdPoint.getX())+
                (thirdPoint.getX() - secondPoint.getX())*(firstPoint.getY()-thirdPoint.getY()));

    double B = ((thirdPoint.getY()- firstPoint.getY())*(p.getX() - thirdPoint.getX())+(firstPoint.getX()-thirdPoint.getX())*
                (p.getY()-thirdPoint.getY())/(secondPoint.getY()-thirdPoint.getY())*(firstPoint.getX()-thirdPoint.getX())+
                (thirdPoint.getX()-secondPoint.getX())*(firstPoint.getY()-thirdPoint.getY()));

    double C = 1.0 - A - B;

    if((A > 0)&&(B>0)&&(C>0))
    {
        return true;
    }
    else{
        return false;
    }
}

bool Triangle::operator>(Point& p)
{
    double A = ((secondPoint.getY()-thirdPoint.getY())*(p.getX()-thirdPoint.getX())+(thirdPoint.getX()-secondPoint.getX())*
                (p.getY()-thirdPoint.getY())/((secondPoint.getY()-thirdPoint.getY())*(firstPoint.getX()-thirdPoint.getX())+
                                              (thirdPoint.getX()-secondPoint.getX())*(firstPoint.getY()-thirdPoint.getY())));

    double B = ((thirdPoint.getY()-firstPoint.getY())*(p.getX()-thirdPoint.getX())+(firstPoint.getX()-thirdPoint.getX())*
                (p.getY()-thirdPoint.getY())/((secondPoint.getY()-thirdPoint.getY())*(firstPoint.getX()-thirdPoint.getX))+
                (thirdPoint.getX()-secondPoint.getX())*(firstPoint.getY()-thirdPoint.getY()));

    double C = 1.0 - A - B;

    if((A>0)&&(B>0)&&(C>0))
    {
        return false;
    }
    else{
        return true;
    }
}

bool Triangle::operator==(Point& p)
{
    double A = ((secondPoint.getY()-thirdPoint.getY())*(p.getX()-thirdPoint.getX())+(thirdPoint.getX()-secondPoint.getX())*
                (p.getY()-thirdPoint.getY())/((secondPoint.getY()-thirdPoint.getY())*(firstPoint.getX()-thirdPoint.getX())+
                                              (thirdPoint.getX()-secondPoint.getX())*(firstPoint.getY()-thirdPoint.getY())));

    double B = ((thirdPoint.getY()-firstPoint.getY())*(p.getX()-thirdPoint.getX())+(firstPoint.getX()-thirdPoint.getX())*
                (p.getY()-thirdPoint.getY())/((secondPoint.getY()-thirdPoint.getY())*(firstPoint.getX()-thirdPoint.getX())+
                                              (thirdPoint.getX()-secondPoint.getX())*(firstPoint.getY()-thirdPoint.getY())));

    double C = 1.0 - A - B;

    if((A==0)&&(B==0)&&(C==0))
    {
        return true;
    }
    else{
        return false;
    }
}
