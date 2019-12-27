
#ifndef PROJECT_CONNECTCOMAND_H
#define PROJECT_CONNECTCOMAND_H

#include "Command.h"
#include <vector>
#include <regex>
class ConnectCommand :public Command{
    vector<string>::iterator &iterator1;
public:
    ConnectCommand(vector<string>::iterator &iterator1);

    void doCommand(vector<string> &text);
};


#endif //PROJECT_CONNECTCOMAND_H