
#ifndef PROJECT_CONDITIONPARSER_H
#define PROJECT_CONDITIONPARSER_H


#include <list>
#include "Command.h"
#include "Expression.h"
#include "extractExpression.h"
//conditionParser
class conditionParser : public Command{
public:
    // constructor
    conditionParser();
    // check condition
    bool condition(vector<string> conditionVec);
    // if it's operator
    bool isBooleanOperator(string op);
    void doCommand(vector<string> &operation);
    bool isOperator(string ifOperator);
    // if it's seprated
    bool isSeparated(vector<string>::iterator it);
    // compare
    bool compare(double e1Val, double e2Val, string op);
};


#endif //PROJECT_CONDITIONPARSER_H
