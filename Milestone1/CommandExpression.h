
#ifndef PROJECT_COMMANDEXPRESSION_H
#define PROJECT_COMMANDEXPRESSION_H

#include <vector>
#include "Expression.h"
#include "Command.h"
//command expression class that implement dessign pattern which is object adapter.
class CommandExpression : public Expression {
protected:
    // vector of the string
    vector<string> &linesFromText;
    // command pointer
    Command *command;
public:
    CommandExpression(vector<string> &linesFromText, Command *command);
    virtual double calculate();
};


#endif //PROJECT_COMMANDEXPRESSION_H
