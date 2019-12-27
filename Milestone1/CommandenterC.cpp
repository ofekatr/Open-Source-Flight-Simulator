//
// Created by issa on 12/23/18.
//

#include "CommandenterC.h"
// function used to wait for the user to type the to contiune the program
void CommandenterC::doCommand(vector<string> &text) {
    char c;
    cin >> c;
    iterator1++;
}
// constrctor.
CommandenterC::CommandenterC(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator1)
        : iterator1(iterator1) {}
