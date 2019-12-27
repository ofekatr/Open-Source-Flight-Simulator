#include "CommandExpression.h"
// constrcutor
CommandExpression::CommandExpression(vector<string> &linesFromText, Command *command) : linesFromText(
        linesFromText), command(command) {}
// here the object adapter get to action, calculate to connect the expression and command.
double CommandExpression::calculate() {
    this->command->doCommand(linesFromText);
    return 1;
}




