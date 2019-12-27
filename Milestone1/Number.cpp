//
// Created by issa on 12/10/18.
//

#include "Number.h"
#include "expressionList.h"
// add to the l;ist and inilizte the nubmer
Number::Number(double number) {
    this->valueNumber = number;
    expressionList::instance()->setValue(this);
}
// basically it is ta number.
double Number::calculate() {
    return valueNumber;
}
