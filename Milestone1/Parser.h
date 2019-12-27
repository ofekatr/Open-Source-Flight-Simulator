//
// Created by issa on 12/12/18.
//
#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include "Expression.h"
#include "whileCommand.h"
#include "ifCommand.h"
#include "DefineVarCommand.h"
#include "printCommand.h"
#include "CommandExpression.h"
#include "OpenServerCommand.h"
#include <regex>
#include "extractExpression.h"
#include "ConnectCommand.h"
#include "Sleep.h"
#include <bits/stdc++.h>
using namespace std;
class Parser {
private:
    // mapss for command / expression.
    // vector string toInterpret and iterator over it.
    map<string, Expression*> expressionMap;
    map<string, Command*> commandMap;
    vector<string> &toInterpret;
    vector<string>::iterator it;
public:
    // constructor.
    Parser(vector<string> &text);
    // function that used to
    void split();
    // distructor
    ~Parser();
    // creating the commands.
    void createCommand();
    // check if the iteartor stand of var from the symbol table.
    bool symbolExists(string st);
};


#endif //PROJECT_PARSER_H