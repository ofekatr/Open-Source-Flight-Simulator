//
// Created by issa on 12/12/18.
//

#include "printCommand.h"
#include "SymbolTable.h"
// constrctor.
printCommand::printCommand(vector<string>::iterator &iterator1) : iterator1(iterator1) {}
// make the command.
void printCommand::doCommand(vector<string> &text) {
    // save the string that we want to print
    string output = *++iterator1;
    // check if it's from the symbol table
    if (SymbolTable::instance()->atTable(output)) {
        cout << output + " " << SymbolTable::instance()->getValue(output) << "\n";
    } else {
        // if not it's a string.
        cout << output << endl;
    }
    // advance iterator.
    ++iterator1;
}
