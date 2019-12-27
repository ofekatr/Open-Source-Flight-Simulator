#include "Parser.h"
#include "CommandenterC.h"

#define command 0
// constructor that takes the vector string and makes on iterator
Parser::Parser(vector<string> &text) : toInterpret(text) {
    this->it = this->toInterpret.begin();
}

void Parser::createCommand() {
    // iniliazte the maps.
    this->commandMap["openDataServer"] = new OpenServerCommand(it);
    this->expressionMap["openDataServer"] = new CommandExpression(toInterpret, this->commandMap["openDataServer"]);
    this->commandMap["connect"] = new ConnectCommand(it);
    this->expressionMap["connect"] = new CommandExpression(toInterpret, this->commandMap["connect"]);
    this->commandMap["var"] = new DefineVarCommand(it);
    this->expressionMap["var"] = new CommandExpression(toInterpret, this->commandMap["var"]);
    this->commandMap["while"] = new whileCommand(it);
    this->expressionMap["while"] = new CommandExpression(toInterpret, this->commandMap["while"]);
    this->commandMap["if"] = new ifCommand(it);
    this->expressionMap["if"] = new CommandExpression(toInterpret, this->commandMap["if"]);
    this->commandMap["print"] = new printCommand(it);
    this->expressionMap["print"] = new CommandExpression(toInterpret, this->commandMap["print"]);
    this->commandMap["EnterC"] = new CommandenterC(it);
    this->expressionMap["EnterC"] = new CommandExpression(toInterpret, this->commandMap["EnterC"]);
    this->commandMap["sleep"] = new Sleep(it);
    this->expressionMap["sleep"] = new CommandExpression(toInterpret, this->commandMap["sleep"]);
    split();
}

void Parser::split() {
    while (it != this->toInterpret.end()) {
        Expression *expression;
        // if symbol instead of command var, assign the define command.
        if (symbolExists(*it))
            expression = this->expressionMap.find("var")->second;
        else
            expression = this->expressionMap.find(*it)->second;
        //call the expression command.
        if (expression != nullptr) {
            expression->calculate();
        }
    }
}
// if it's exists.
bool Parser::symbolExists(string var) {
    for (auto iter = SymbolTable::instance()->getBegin(); iter != SymbolTable::instance()->getEnd(); iter++) {
        if (SymbolTable::instance()->atTable(var)) {
            return true;
        }
    }
    return false;
}
// distructor , realse all the alloacted memory of the command and the expresion map
Parser::~Parser() {
    for (auto itemp = this->expressionMap.begin();
         itemp != this->expressionMap.end(); itemp++) {
        map<string,Command*>::iterator t = this->commandMap.find(itemp->first);
        delete t->second;
        delete itemp->second;
    }
}
