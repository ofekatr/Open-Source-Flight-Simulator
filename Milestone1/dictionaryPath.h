//
// Created by issa on 12/20/18.
//
#ifndef PROJECT_DICTIONARYPATH_H
#define PROJECT_DICTIONARYPATH_H

#include <map>
#include "mutex"
#include "unordered_map"
using namespace std;
// dictionaty path
class dictionaryPath {
    //mutex
    mutex thisLock;
    // hashMap
    unordered_map<string, double> pathMap;
    // instance
    static dictionaryPath *map_instance;
public:
    // constructor of the map
    static inline dictionaryPath *instance() {
        if (map_instance == nullptr) {
            map_instance = new dictionaryPath();
        }
        return map_instance;
    }
    // set value.
    inline void setValue(string &key, double val) {
        thisLock.lock();
        pathMap[key] = val;
        thisLock.unlock();
    }
    // get the map
    inline unordered_map<string, double > &getMap() {
        return pathMap;
    }
    // get the value
    inline double getValue(const string &key) {
        thisLock.lock();
        double value = pathMap.find(key)->second;
        thisLock.unlock();
        return value;
    }
    // delete
    ~dictionaryPath(){
        delete map_instance;
    }
    // in map
    inline bool atTable(string &key) {
        return pathMap.find(key) != pathMap.end();
    }
    // get the path
    bool getPath(const string &string1){
        if(pathMap.count(string1) > 0){
            return true;
        }else{
            return false;
        }
    }
};


#endif //PROJECT_DICTIONARYPATH_H
