//
// Created by issa on 12/12/18.
//
#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include <iostream>
#include <vector>
#include "conditionParser.h"
#include "Parser.h"
// ifCommand class
class ifCommand : public conditionParser {
    //iterator by pointer.
    vector<string>::iterator &iterator1;
public:
    // if command constructor.
    ifCommand(vector<string>::iterator &iter);
    // do command function.
    void doCommand(vector<string> &text);
};

#endif //PROJECT_IFCOMMAND_H
