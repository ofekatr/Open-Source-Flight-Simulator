//
// Created by issa on 12/10/18.
//
#ifndef PROJECT_DIV_H
#define PROJECT_DIV_H


#include "BinaryExpression.h"
// div class
class Div : public BinaryExpression{
public:
    //constructor
    Div(Expression *left, Expression *right);
    // distuctor.
    ~Div();
    // calculate
    double calculate();
};


#endif //PROJECT_DIV_H
