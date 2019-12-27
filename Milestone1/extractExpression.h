//
// Created by issa on 12/18/18.
//
#ifndef PROJECT_EXTRACTEXPRESSION_H
#define PROJECT_EXTRACTEXPRESSION_H
using namespace std;
#include <vector>
#include <string>
#include <list>
#include <map>
#include "SymbolTable.h"
#include "ShuntingYard.h"

class extractExpression {
public:
    // made the expression.
    static Expression *extract(vector<string>::iterator &iter, vector<string> &vec);
    // to know when we should stop.
    static bool isCommand(string str);
};


#endif //PROJECT_EXTRACTEXPRESSION_H