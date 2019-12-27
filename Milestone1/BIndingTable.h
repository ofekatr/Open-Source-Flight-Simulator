//
// Created by issa on 12/20/18.
//

#ifndef PROJECT_BINDINGTABLE_H
#define PROJECT_BINDINGTABLE_H
using namespace std;

#include "unordered_map"
#include <map>
#include <string>
// senegleton map that will hold a map from string to strin, to store the var and that path of every var that
// we will ad to our program
class BIndingTable {
    // hashMap
    unordered_map<string, string> bindMap;
    // instance of the map
    static BIndingTable *map_instance;
public:
    // constructor for calling
    static inline BIndingTable *instance() {
        if (map_instance == nullptr) {
            map_instance = new BIndingTable();
        }
        return map_instance;
    }
    // destrctor
    ~BIndingTable() {
        delete map_instance;
    }
    // set our value on the table.
    inline void setValue(string &key, string val) {
        bindMap[key] = val;
    }
    // search on the map if the var on it.
    inline string getValue(const string &key) {
        unordered_map<string, string>::iterator i = bindMap.find(key);
        if (i == bindMap.end())
            return "";
        string path = i->second;
        return path;
    }
    // get the map by ref.
    inline unordered_map<string, string> &getMap() {
        return bindMap;
    }
    // check if it in the table.
    inline bool atTable(string &key) {
        return bindMap.find(key) != bindMap.end();
    }
};


#endif //PROJECT_BINDINGTABLE_H
