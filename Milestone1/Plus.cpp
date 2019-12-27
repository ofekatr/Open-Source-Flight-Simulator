//
// Created by issa on 12/10/18.
//

#include "Plus.h"
// constructor that used for plus, we added the instance to list by singelton dessing pattern.
Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {
    expressionList::instance()->setValue(this);
}
// calculate the expression
double Plus::calculate() {
    return this->left->calculate() + this->right->calculate();
}
// destructor.
Plus::~Plus() {
    if (left != nullptr) {
        delete left;
    }
    if (right != nullptr) {
        delete right;
    }
}
