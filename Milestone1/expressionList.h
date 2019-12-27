//
// Created by issa on 12/23/18.
//

#ifndef PROJECT_EXPRESSIONLIST_H
#define PROJECT_EXPRESSIONLIST_H


#include "Expression.h"
#include "list"

using namespace std;

class expressionList {
    //list of expression
    list<Expression *> expMap;
    // instance of it
    static expressionList *map_instance;
public:
    // static constructor
    static inline expressionList *instance() {
        if (map_instance == nullptr) {
            map_instance = new expressionList();
        }
        return map_instance;
    }
    // set the vaule
    inline void setValue(Expression *exp) {
        expMap.push_back(exp);
    }
    // distructor.
    ~expressionList() {
        for (auto &itemp : expMap) {
            if(itemp != nullptr) {
                delete itemp;
            }
        }
        delete map_instance;
    }
};


#endif //PROJECT_EXPRESSIONLIST_H
