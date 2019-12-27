//
// Created by issa on 12/10/18.
//

#ifndef PROJECT_MUL_H
#define PROJECT_MUL_H


#include "BinaryExpression.h"
// mult (*) opearation
class Mul : public BinaryExpression{
public:
    // constructor.
    Mul(Expression *left, Expression *right);
    // distructor
    ~Mul();
    // calculate
    double calculate();
};


#endif //PROJECT_MUL_H
