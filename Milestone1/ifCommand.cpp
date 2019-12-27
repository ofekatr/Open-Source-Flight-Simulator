//
// Created by issa on 12/12/18.
//

#include "ifCommand.h"

void ifCommand::doCommand(vector<string> &text) {
    iterator1++; // Now stands on expression part.
    vector<string> conditionVec, commandsVec;
    // till we see a { that is the condition
    while (*iterator1 != "{") {
        conditionVec.push_back(*iterator1);
        iterator1++;
    }
    int braks = 0;
    //advance
    iterator1++;
    while (!(*iterator1 == "}" && braks == 0)) {
        if (*iterator1 == "{")
            braks++;
        if (*iterator1 == "}")
            braks--;
        commandsVec.push_back(*iterator1);
        iterator1++;
    }
    // check the condition
    if (condition(conditionVec)){
        Parser pars(commandsVec);
        pars.createCommand();
    }
    iterator1++;
}

ifCommand::ifCommand(vector<string>::iterator &iterator1): iterator1(iterator1) {}