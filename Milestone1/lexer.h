//
// Created by issa on 12/17/18.
//
#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include "Parser.h"
class lexer {
public:
    // get the lines from the file.
    vector<string> lexerToTextFile(const string &lexer);
    // split by " " and string.
    vector<string> splitLine(const string& line);
    // function that split all the string by " ".
    void spacer(string &after);
    // if it's number
    bool ifNumber(char number);
    // if it's '('
    bool isLeftParentheses(char parentheses);
    // if it's ')'
    bool isRightParentheses(char parnthese);
    // if it's operator.
    bool isOperator(char operation);
};


#endif //PROJECT_LEXER_H
