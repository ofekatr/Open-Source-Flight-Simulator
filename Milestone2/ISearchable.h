//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_ISEARCHABLE_H
#define MAILSTONE2_ISEARCHABLE_H
#include "vector"
#include "State.h"

using namespace std;
template <class T>
class ISearchable{
public:
    virtual State<T> *getInitialState()=0;
    virtual bool isGoalState(State<T> *state) = 0;
    virtual vector<State<T> *> getAllPossibleState(State<T> *state) = 0;
};
#endif //MAILSTONE2_ISEARCHABLE_H