//
// Created by jokereed on 1/10/19.
//

#ifndef MAILSTONE2_COMPAREPRIORITY_H
#define MAILSTONE2_COMPAREPRIORITY_H

#include "State.h"
#include "Coordinates.h"

template<class T>
struct ComparePriority {
public:
    // Compares distances for algorithms such as BestFirstSearch.
    bool operator()(State<T>* a, State<T>* b){
        return a->getCost() > b->getCost();
    }
};

template<class T>
struct ManhattanDistances {
public:
    // Compares distances using heuristics for algorithms such as Astar.
    bool operator()(State<T>* a, State<T>* b) {
        return a->getCost() + a->getHeuristic() > b->getCost() + b->getHeuristic();
    }
};
#endif //MAILSTONE2_COMPAREPRIORITY_H
