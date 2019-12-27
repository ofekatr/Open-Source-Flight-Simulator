//
// Created by issa on 1/13/19.
//

#include "Splitter.h"

vector<string> Splitter::splitBy(string buffer) {
    vector<string> vecAfterSplit;
    while (buffer.size() > 0) {
        int i = buffer.find(',');
        if (i != string::npos) {
            vecAfterSplit.push_back(buffer.substr(0,i));
            buffer = buffer.substr(i + 1);
            if(buffer.size() == 0){
                vecAfterSplit.push_back(buffer);
            }
        }else{
            vecAfterSplit.push_back(buffer);
            buffer = "";
        }
    }
    return vecAfterSplit;
}
/*
 * vector<string> vecAfterSplit;
    string temp;
    for (char &i : buffer) {
        if(i ==  ' ' || i == ','){
            continue;
        }
        vecAfterSplit.emplace_back(i);
        //temp = "";
        //if (buffer[i] != '\n') ++i;
    }
    return vecAfterSplit;
 */
