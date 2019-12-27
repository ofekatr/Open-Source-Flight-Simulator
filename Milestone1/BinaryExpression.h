
#ifndef PROJECT_BINARYEXPRESSION_H
#define PROJECT_BINARYEXPRESSION_H

#include "Expression.h"
#include "expressionList.h"
// abstract class that inherent from Expression, used for calculation in the operators.
// inherent two expression that we will do calculate on them.
class BinaryExpression : public Expression{
protected:
    // left expression
    Expression *left;
    // right expression
    Expression *right;
public:
    BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}
};

#endif //PROJECT_BINARYEXPRESSION_H
