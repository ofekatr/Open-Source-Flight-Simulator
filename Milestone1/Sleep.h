//
// Created by issa on 12/16/18.
//
#ifndef PROJECT_SLEEP_H
#define PROJECT_SLEEP_H


#include "Command.h"
#include <unistd.h>
class Sleep : public Command{
    // iterator that get by ref.
    vector<string>::iterator &iterator1;
public:
    // constructor.
    Sleep(vector<string>::iterator &iterator1);
    // method that we inherent fromt he command interface.
    void doCommand(vector<string> &text);
};


#endif //PROJECT_SLEEP_H
