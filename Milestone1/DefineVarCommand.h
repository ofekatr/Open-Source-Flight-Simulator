
#ifndef PROJECT_DEFINEVARCOMAND_H
#define PROJECT_DEFINEVARCOMAND_H

#include "Command.h"
#include "extractExpression.h"
#include "BIndingTable.h"
#include <map>
using namespace std;
// defineVarCommand var
class DefineVarCommand :public Command{
    // iteator by ref
    vector<string>::iterator &iterator1;
public:
    // constructor
    DefineVarCommand(vector<string>::iterator &iterator1);
    // doCommand
    void doCommand(vector<string> &text);
};


#endif //PROJECT_DEFINEVARCOMAND_H