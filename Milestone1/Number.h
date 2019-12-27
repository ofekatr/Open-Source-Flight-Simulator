//
// Created by issa on 12/10/18.
//

#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H


#include "Expression.h"
// class number
class Number : public Expression{
    double valueNumber;
public:
    Number(double value);
    double calculate();
};


#endif //PROJECT_NUMBER_H
