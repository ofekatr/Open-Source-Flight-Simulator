#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
//#include <string.h>
using namespace std;
/*
 * interface for the interpreter.
 */
//mutex to lock the sets/
static mutex useMutex;
class Command {
public:
    // default command.
    virtual ~Command() = default;
    // execute the specific command.
    virtual void doCommand(vector<string> &operation) = 0;
};

#endif //PROJECT_COMMAND_H
