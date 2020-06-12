#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <iostream>

class VLE : public std::exception{
public:
    const char * what (){
        return "Vector length cannot be 0 ";
    }
};

class EqualPointException : public std::exception{
public:
    EqualPointException(int num1, int num2){
        this->num1=num1;
        this->num2=num2;

    }
    const char * pointsException (){
        std::cout<<num1<< " " << num2;
        return "Matching points";
    }
private:
    int num1;
    int num2;
};


#endif // EXCEPTIONS_H_INCLUDED
