//
// Created by issa on 12/23/18.
//

#ifndef PROJECT_COMMANDENTERC_H
#define PROJECT_COMMANDENTERC_H


#include "Command.h"
// get char class
class CommandenterC : public Command {
    //iterator that moved by ref.
    vector<string>::iterator &iterator1;
public:
    // constructor for the class
    CommandenterC(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator1);
    //function that inherent from the command interface
    void doCommand(vector<string> &text);
};


#endif //PROJECT_COMMANDENTERC_H
