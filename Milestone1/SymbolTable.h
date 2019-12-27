#pragma once

#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#endif //PROJECT_SYMBOLTABLE_H

#include "unordered_map"
#include <string>
#include <map>
#include <mutex>

using namespace std;
// symbol table calss, that hold the variable.
class SymbolTable {
    // hash map of the symbolMap.
    unordered_map<string, double> symbolMap;
    // instance of the map.
    static SymbolTable *map_instance;
public:
    // constructor that here we iniliaze the map.
    static inline SymbolTable *instance() {
        if (map_instance == nullptr) {
            map_instance = new SymbolTable();
        }
        return map_instance;
    }
    // get the map
    const unordered_map<string, double> &getMap() const {
        return symbolMap;
    }
    // destuctor.
    ~SymbolTable() {
        delete map_instance;
    }
    // set values.
    inline void setValue(const string &key, double val) {
        symbolMap[key] = val;
    }
    // get value.
    inline double getValue(const string &key) {
        unordered_map<string, double>::iterator i = symbolMap.find(key);
        if (i == symbolMap.end())
            return 0;
        return i->second;
    }
    // find if it's in the table.
    inline bool atTable(string &key) {
        return symbolMap.find(key) != symbolMap.end();
    }
    // return the hash map iterator of begin
    inline unordered_map<string, double>::iterator getBegin() {
        return symbolMap.begin();
    }
    // return the hashMap iterator of the end
    inline unordered_map<string, double>::iterator getEnd() {
        return symbolMap.end();
    }
};