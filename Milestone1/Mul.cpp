//
// Created by issa on 12/10/18.
//

#include "Mul.h"
// set the mul and add it to the list.
Mul::Mul(Expression *left, Expression *right) : BinaryExpression(left, right) {
    expressionList::instance()->setValue(this);
}
// makes the operation
double Mul::calculate() {
    return this->left->calculate() * this->right->calculate();
}
// distructor.
Mul::~Mul() {
    if (left != nullptr) {
        delete left;
    }
    if (right != nullptr) {
        delete right;
    }
}
