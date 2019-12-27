//
// Created by issa on 12/18/18.
//

#include "extractExpression.h"
// this function used to extract the string that represent the expression.
// it's based on the logic of when we should stop the get the strings. base on knowing for explame that after
// operator we sould not take the next him to the vector<string> if it's operator
Expression *extractExpression::extract(vector<string>::iterator &it, vector<string> &vec) {
    vector<string> ex;
    // get the map
    unordered_map<string,double > symbols = SymbolTable::instance()->getMap();
    int counter = 1;
    //case if it's neg.
    bool neg = true;
    //vector<string>::iterator it = vec.begin();
    int brac = 0;
    while (it != vec.end()) {
        if (isCommand(*it))
            break;
        // Numbers.
        if (ShuntingYard::isNumber(*it)) {
            if (counter != 0) {
                ex.push_back(*it);
                if (brac == 0)
                    counter--;
                ++it;
                neg = false;
                continue;
            }
            break;
        }
        // Brackets.
        if (ShuntingYard::isRightParen(*it)) {
            neg = false;
            brac--;
            if (brac == 0) {
                counter--;
            }
            ex.push_back(*it);
            it++;
            continue;
        }
        if (ShuntingYard::isLeftParen(*it)) {
            if (counter == 0)
                break;
            neg = true;
            brac++;
            ex.push_back(*it);
            it++;
            continue;
        }
        // Operators.
        if (ShuntingYard::isOperator(*it)) {
            if (!brac && !neg)
                counter++;
            ex.push_back(*it);
            neg = true;
            it++;
            continue;
        }
            // Vars.
        else {
            if (counter) {
                neg = false;
                ex.push_back(to_string(symbols[*it]));
                if (!brac)
                    counter--;
                it++;
                continue;
            }
            break;
        }
    }
    // after we made the string to send it to evaulate.
    return ShuntingYard::evaluate(ex);
}

bool extractExpression::isCommand(string str) {
    if (str == "connect" || str == "var" || str == "openDataServer" || str == "print" || str == "sleep" ||
        str == "while"
        || str == "if") {
        return true;
    }
}