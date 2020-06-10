#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <iostream>

class VLE : public std::exception{
public:
    const char * what (){
        return "Vector length cannot be 0 ";
    }
};



#endif // EXCEPTIONS_H_INCLUDED
