//
// Created by issa on 12/10/18.
//
#ifndef PROJECT_MINUS_H
#define PROJECT_MINUS_H


#include "BinaryExpression.h"
// minus operation
class Minus : public BinaryExpression{
public:
    // constructor
    Minus(Expression* left, Expression *right);
    // distructor.
    ~Minus();
    // makes the operation.
    double calculate();
};


#endif //PROJECT_MINUS_H
