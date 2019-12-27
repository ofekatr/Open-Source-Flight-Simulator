//
// Created by jokereed on 1/9/19.
//

#ifndef MAILSTONE2_PRIORITYSEARCHER_H
#define MAILSTONE2_PRIORITYSEARCHER_H

#include "Searcher.h"

template<class S, class T>
class PrioritySearcher : public Searcher<S, T> {
    /*
    void adjustPriority(priority_queue<State<T>> openList, State<T> state) {
        State<T> nearByState = NULL;
        for (auto i : openList) {
            if (nearByState == state) {
                openList.pop();
                setDeterminedCost(nearByState);
                openList.push(nearByState);
                return;
            }
        }
    }
    int openListSize() {
        return static_cast<int>(this->opened->size());
    }*/
};


#endif //MAILSTONE2_PRIORITYSEARCHER_H