//
// Created by issa on 12/13/18.
//
#ifndef PROJECT_SHUNTINGYARD_H
#define PROJECT_SHUNTINGYARD_H
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include "Expression.h"
#include "Expression.h"
#include "Plus.h"
#include "Number.h"
#include "Minus.h"
#include "Div.h"
#include "Mul.h"

using namespace std;
class ShuntingYard {
public:
    // check if leftParen
    static bool isLeftParen(string st);
    // check if reight paren
    static bool isRightParen(string st);
    // makes the expression
    static Expression* calc(Expression *left, Expression *right, string st);
    // check if it's operator
    static bool isOperator(string st);
    // check if it's number
    static bool isNumber(string st);
    // check if it's precedence
    static int precedence(string st);
    // to string
    static string toString(int num);
    // to postfix
    static vector<string> toPostfix(vector<string> ex);
    // stack of the operations
    static void stackOperations(string op, vector<string> &ex, stack<string> &stack1, bool neg);
    // evaluate the expression
    static Expression* evaluate(vector<string> ex);
    // more than one
    static bool moreThan2(stack<Expression*> s);
};



#endif //PROJECT_SHUNTINGYARD_H