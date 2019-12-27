//
// Created by issa on 12/10/18.
//

#include "Minus.h"
// constructor + add to the list.
Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left, right) {
    expressionList::instance()->setValue(this);
}
// calculate the minus
double Minus::calculate() {
    return this->left->calculate() - this->right->calculate();
}
// distructor.
Minus::~Minus() {
    if (left != nullptr) {
        delete left;
    }
    if (right != nullptr) {
        delete right;
    }
}
