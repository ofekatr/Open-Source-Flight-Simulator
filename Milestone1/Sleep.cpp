//
// Created by issa on 12/16/18.
//

#include "Sleep.h"
#include "extractExpression.h"
#define THOUSANDS 1000
// constructor
Sleep::Sleep(vector<string>::iterator &iterator1)
        : iterator1(iterator1) {}
//
void Sleep::doCommand(vector<string> &text) {
    sleep(extractExpression::extract(++iterator1, text)->calculate()/THOUSANDS);
}
