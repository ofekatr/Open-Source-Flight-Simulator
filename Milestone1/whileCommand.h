
#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H

#include "conditionParser.h"
#include <vector>
#include "Parser.h"

class whileCommand : public conditionParser{
    vector<string>::iterator &iterator1;
public:

    whileCommand(vector<string>::iterator &iterator1);

    void doCommand(vector<string> &text);

};


#endif //PROJECT_WHILECOMMAND_H
