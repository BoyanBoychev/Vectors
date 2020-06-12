#include "triangle.h"
#include "exceptions.h"
#include <cmath>

///Конструктор в който имаме проверка за валидност на триъгълник.
Triangle::Triangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint){
    if(firstPoint.getX() == secondPoint.getX() && firstPoint.getY() == secondPoint.getY()) throw EqualPointException(1,2);
    if(firstPoint.getX() == thirdPoint.getX() && firstPoint.getY() == thirdPoint.getY()) throw EqualPointException(1,3);
    if(secondPoint.getX() == thirdPoint.getX() && secondPoint.getY() == thirdPoint.getY()) throw EqualPointException(2,3);

    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->thirdPoint = thirdPoint;
}

///Полупериметър на триъгълник
double Triangle::poluPerimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///формула за полупериметър сбор на 3 страни, който се дели на 2.
    return(firstPoint.getX() + secondPoint.getY() + ThirdPoint.getZ())/2;
}
/// Проверка за тип на триъгълник.
void Triangle::checkTriangleType(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{


        ///Проверка за равностранен триъгълник, като сравняваме страните му.
        if(firstPoint.getX() == secondPoint.getY() && secondPoint.getY() == ThirdPoint.getZ()){
            cout<<"Ravnostranen"<<endl;
        }

        ///Проверка за равнобедрен триъгълник, като сравняваме страните му.
        else if(firstPoint.getX() == secondPoint.getY()|| secondPoint.getY() == ThirdPoint.getZ() ||
                ThirdPoint.getZ() == firstPoint.getX())
        {
                    cout<<"Ravnobedren"<<endl;
        }

        else
        {
            cout<<"Raznostranen"<<endl;
        }


        ///Проверка за най-голяма страна в триъгълника, за улеснение, за проверка на типа на триъгълника.
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

    ///Проверка за правоъгълен триъгълник по формулата c^2 = a^2 + b^2.
    if(firstPoint.getX()*firstPoint.getX() + secondPoint.getY()*secondPoint.getY() == longest*longest)
    {
        cout<<"Pravougulen"<<endl;

    }
    ///Проверка за остроъгълен триъгълник по формулата a^2 + b^2 > c^2.
    else if(firstPoint.getX()*firstPoint.getX() + secondPoint.getY()*secondPoint.getY() >longest*longest)
    {
        cout <<"Ostrougulen"<<endl;
    }
    else
    {
        cout<<"Tupougulen"<<endl;
    }

}

///Метод за изчисление на лице на триъгълник по Херонова формула.
double Triangle::areaTriangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///Намираме полупериметъра на триъгълника, чрез метода по-горе.
    double p = poluPerimetar(firstPoint,secondPoint,ThirdPoint);

    ///херонова формула.
    return sqrt(p*(p-firstPoint.getX())*(p-secondPoint.getY())*(p-ThirdPoint.getZ()));
}

///Метод за намиране на периметъра на триъгълник a+b+c.
double Triangle::perimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return (firstPoint.getX() + secondPoint.getY() + ThirdPoint.getZ());
}

///Метод за намиране на медиана 1.
double Triangle::mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///формула за намиране на медиана на mX(mA).
    return(sqrt(2*(ThirdPoint.getZ()*ThirdPoint.getZ())+2*(secondPoint.getY()*secondPoint.getY())-
                (firstPoint.getX()*firstPoint.getX()))/2);
}
///Метод за намиране на медиана 2.
double Triangle::mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///формула за намиране на медиана на mY(mB).
    return (sqrt(2*(ThirdPoint.getZ()*ThirdPoint.getZ())+2*(firstPoint.getX()*firstPoint.getX())-
                 (secondPoint.getY()*secondPoint.getY()))/2);
}
///Метод за намиране на медиана 3.
double Triangle::mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///формула за намиране на медиана на mZ(mC).
    return(sqrt(2*(firstPoint.getX()*firstPoint.getX())+2*(secondPoint.getY()*secondPoint.getY())-
                (ThirdPoint.getZ()*ThirdPoint.getZ()))/2);
}
///Метод за намиране на медицентър.
double Triangle::mediCentar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{

    double m1 = mX(firstPoint, secondPoint, ThirdPoint);
    double m2 = mY(firstPoint, secondPoint, ThirdPoint);
    double m3 = mZ(firstPoint, secondPoint, ThirdPoint);

    ///формула за медицентър.
    return ((m1 + m2 + m3)/3);
    /*((mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint))/3);
    */
}

