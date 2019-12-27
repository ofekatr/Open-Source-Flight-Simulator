//
// Created by issa on 12/15/18.
//

#include "conditionParser.h"

conditionParser::conditionParser(){}

bool conditionParser::condition(vector<string> conditionVec){

    vector<string>::iterator it = conditionVec.begin();
    string op = "";
    vector<string> e1, e2;
    bool sep = isSeparated(it);
    if (!sep)
        it++;
    // Now stands on expression1
    while (!isBooleanOperator(*it)) {
        e1.push_back(*it);
        it++;
    }
    //Now stands on operator
    while (isBooleanOperator(*it)) {
        op.append(*it);
        it++;
    }
    //Now stands on expression2
    while (it != conditionVec.end()) {
        e2.push_back(*it);
        it++;
    }
    if (!sep){
        while (*--it != ")")
            e2.erase(it);
        e2.erase(it);
    }
    vector<string>::iterator itE1 = e1.begin(), itE2 = e2.begin();
    double e1Val = extractExpression::extract(itE1, e1)->calculate();
    double e2Val = extractExpression::extract(itE2, e2)->calculate();
    return compare(e1Val, e2Val, op);
}
// if there are a ( or )
bool conditionParser::isSeparated(vector<string>::iterator it){
    int brac = 0;
    while (!isBooleanOperator(*it++)){
        if (*it == "(")
            brac++;
        if (*it == ")")
            brac--;
    }
    return brac == 0;
}
bool conditionParser::isBooleanOperator(string op){
    return (op == "=" || op == "<" || op == ">" || op == "!");
}

void conditionParser::doCommand(vector<string> &operation) {}

bool conditionParser::isOperator(string ifOperator) {
    return (ifOperator == ">" || ifOperator == "<" || ifOperator == ">=" || ifOperator == "<="
           || ifOperator == "!=" || ifOperator == "==");
}
// compare between the values/
bool conditionParser::compare(double e1Val, double e2Val, string op){
    if (op == "==")
        return e1Val == e2Val;
    if (op == ">=")
        return e1Val >= e2Val;
    if (op == "<=")
        return e1Val <= e2Val;
    if (op == "<")
        return e1Val < e2Val;
    if (op == ">")
        return e1Val > e2Val;
    if (op == "!=")
        return e1Val != e2Val;
}
