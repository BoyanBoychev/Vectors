#include "Line.h"

Line::Line() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
//конструктор на линия, връща вектор
Line::Line(Point& p1, Point& p2){
    Vector* v1 = new Vector (p1, p2);
    cout << "Line initialized: " <<endl;
    cout << *v1 << endl;
//    if(abs(p1.getX() - p2.getX()) < 0.0001 && abs(p1.getY() - p2.getY()) < 0.0001){
//        throw "Points must have different coordinates";
// }
}
// намира дължина на линия
double Line::lenght(Point& p1,Point& p2){
    double lineX = pow((p2.getX() - p1.getX()),2);
    double lineY = pow((p2.getY() - p1.getY()),2);
    cout << sqrt(lineX + lineY) << endl;
    return sqrt(lineX + lineY);
}
//намира посока на дължина, приема две точки и връща вектор успореден на линията
Vector Line::getDirection(Point& p1, Point& p2) {
    Vector v1 = *this;
    Vector* lineDir = new Vector(p1.getX() - p2.getX(),p1.getY() - p2.getY(),p1.getZ() - p2.getZ());
    cout << *lineDir << endl;
    return *lineDir;
}
/*
Vector Line::normalVector(Line& l1, Point& p1){
    Vector v1;



    return v1;
}
*/

/*Line::Line operator +(Point& p1,Point& pp1, Point& p2, Point& pp2, Point& p3, Point& pp3 ):x1(p1), x2(p2), x3(p3),
y1(pp1), y2(pp2), y3(pp3)
{
    //пресмята наклона на първите 2 точки.
    unsigned slope = (y2-y1) / (x2-x1);
    unsigned onLine = (y3-y1) == slope *(x3-x1);

    if(onLine)
        cout<<"True"<<endl;
    else if((x3==x2)&&(y1<=y3<=y2))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

}
*/
