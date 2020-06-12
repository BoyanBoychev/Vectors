#include "triangle.h"
#include "exceptions.h"
#include <cmath>

///����������� � ����� ����� �������� �� ��������� �� ����������.
Triangle::Triangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint){
    if(firstPoint.getX() == secondPoint.getX() && firstPoint.getY() == secondPoint.getY()) throw EqualPointException(1,2);
    if(firstPoint.getX() == thirdPoint.getX() && firstPoint.getY() == thirdPoint.getY()) throw EqualPointException(1,3);
    if(secondPoint.getX() == thirdPoint.getX() && secondPoint.getY() == thirdPoint.getY()) throw EqualPointException(2,3);

    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->thirdPoint = thirdPoint;
}

///������������� �� ����������
double Triangle::poluPerimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///������� �� ������������� ���� �� 3 ������, ����� �� ���� �� 2.
    return(firstPoint.getX() + secondPoint.getY() + ThirdPoint.getZ())/2;
}
/// �������� �� ��� �� ����������.
void Triangle::checkTriangleType(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{


        ///�������� �� ������������ ����������, ���� ���������� �������� ��.
        if(firstPoint.getX() == secondPoint.getY() && secondPoint.getY() == ThirdPoint.getZ()){
            cout<<"Ravnostranen"<<endl;
        }

        ///�������� �� ����������� ����������, ���� ���������� �������� ��.
        else if(firstPoint.getX() == secondPoint.getY()|| secondPoint.getY() == ThirdPoint.getZ() ||
                ThirdPoint.getZ() == firstPoint.getX())
        {
                    cout<<"Ravnobedren"<<endl;
        }

        else
        {
            cout<<"Raznostranen"<<endl;
        }


        ///�������� �� ���-������ ������ � �����������, �� ���������, �� �������� �� ���� �� �����������.
    double longest = ThirdPoint.getZ();
    if(longest < firstPoint.getX()){
        ThirdPoint.getZ() = longest;
        longest = firstPoint.getX();
        firstPoint.getX() = ThirdPoint.getZ();
    }
    if(longest < secondPoint.getY()){
        ThirdPoint.getZ() = longest;
        longest = secondPoint.getY();
        secondPoint.getY() = ThirdPoint.getZ();
    }

    ///�������� �� ����������� ���������� �� ��������� c^2 = a^2 + b^2.
    if(firstPoint.getX()*firstPoint.getX() + secondPoint.getY()*secondPoint.getY() == longest*longest)
    {
        cout<<"Pravougulen"<<endl;

    }
    ///�������� �� ����������� ���������� �� ��������� a^2 + b^2 > c^2.
    else if(firstPoint.getX()*firstPoint.getX() + secondPoint.getY()*secondPoint.getY() >longest*longest)
    {
        cout <<"Ostrougulen"<<endl;
    }
    else
    {
        cout<<"Tupougulen"<<endl;
    }

}

///����� �� ���������� �� ���� �� ���������� �� �������� �������.
double Triangle::areaTriangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///�������� �������������� �� �����������, ���� ������ ��-����.
    double p = poluPerimetar(firstPoint,secondPoint,ThirdPoint);

    ///�������� �������.
    return sqrt(p*(p-firstPoint.getX())*(p-secondPoint.getY())*(p-ThirdPoint.getZ()));
}

///����� �� �������� �� ���������� �� ���������� a+b+c.
double Triangle::perimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return (firstPoint.getX() + secondPoint.getY() + ThirdPoint.getZ());
}

///����� �� �������� �� ������� 1.
double Triangle::mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///������� �� �������� �� ������� �� mX(mA).
    return(sqrt(2*(ThirdPoint.getZ()*ThirdPoint.getZ())+2*(secondPoint.getY()*secondPoint.getY())-
                (firstPoint.getX()*firstPoint.getX()))/2);
}
///����� �� �������� �� ������� 2.
double Triangle::mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///������� �� �������� �� ������� �� mY(mB).
    return (sqrt(2*(ThirdPoint.getZ()*ThirdPoint.getZ())+2*(firstPoint.getX()*firstPoint.getX())-
                 (secondPoint.getY()*secondPoint.getY()))/2);
}
///����� �� �������� �� ������� 3.
double Triangle::mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///������� �� �������� �� ������� �� mZ(mC).
    return(sqrt(2*(firstPoint.getX()*firstPoint.getX())+2*(secondPoint.getY()*secondPoint.getY())-
                (ThirdPoint.getZ()*ThirdPoint.getZ()))/2);
}
///����� �� �������� �� ����������.
double Triangle::mediCentar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{

    double m1 = mX(firstPoint, secondPoint, ThirdPoint);
    double m2 = mY(firstPoint, secondPoint, ThirdPoint);
    double m3 = mZ(firstPoint, secondPoint, ThirdPoint);

    ///������� �� ����������.
    return ((m1 + m2 + m3)/3);
    /*((mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint))/3);
    */
}

