//
// Created by issa on 12/10/18.
//

#include "Div.h"
// constructor
Div::Div(Expression *left, Expression *right) : BinaryExpression(left, right) {
    expressionList::instance()->setValue(this);
}
// calulate
double Div::calculate() {
    return this->left->calculate() / this->right->calculate();
}
// distructor
Div::~Div() {
    if(left != nullptr) {
        delete left;
    }
    if(right != nullptr) {
        delete right;
    }
}
