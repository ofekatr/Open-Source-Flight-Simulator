//
// Created by issa on 12/10/18.
//
#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H


#include "BinaryExpression.h"
// plus class that inherent from binaryExpression.
class Plus : public BinaryExpression{
public:
    // constructor.
    Plus(Expression *left, Expression *right);
    // destructor
    ~Plus();
    // calculate that inherent from expression
    double calculate();

};


#endif //PROJECT_PLUS_H
