//
// Created by issa on 1/6/19.
//

#ifndef MAILSTONE2_ASTAR_H
#define MAILSTONE2_ASTAR_H

#include "ISearcher.h"
#include "Comparators.h"
#include "MyPriorityQueue.h"
#include "PrioritySearcher.h"
#include "Comparators.h"
#include "Searcher.h"

template<class S, class T>
class Astar : public Searcher<S, T> {
    MyPriorityQueue<State<T> *, ManhattanDistances<T>> opened;
public:
    S search(ISearchable<T> *searchable) {
        this->NumberOfNodesEvaluated = 0;
        this->addToOpenList(searchable->getInitialState());
        while (!this->opened.empty()) {
            State<T> *n = this->popOpenList();
            this->closed.insert(n);
            if (searchable->isGoalState(n)) {
                /*
                for (State<T> *temp:this->closed) {
                    delete temp;
                }
                 */
                this->closed.clear();
                while (!opened.empty()) {
                    //State<T> *popped = opened.top();
                    opened.pop();
                    //delete popped;
                }
                return this->backtrace(n);
            } else {
                for (State<T> *s : searchable->getAllPossibleState(n)) {
                    if (!this->opened.contains(s) && !this->closedContains(s)) {
                        this->addToOpenList(s);
                    } else if (!this->closedContains(s)) {
                        updateStatePriority(s);
                    }
                }
            }
        }
    }

    // Pop and return the top vertex in the opened.
    State<T> *popOpenList() {
        if (!this->opened.empty()) {
            this->NumberOfNodesEvaluated++;
            State<T> *popped = this->opened.top();
            this->opened.pop();
            return popped;
        }
        return NULL;
    }

    // Add a vertex to the opened.
    void addToOpenList(State<T> *state) {
        this->opened.push(state);
    }

    // Check if opened contains a vertex.
    bool openContains(State<T> *state) {
        auto first = this->opened.cbegin();
        auto last = this->opened.cend();
        while (first != last) {
            if (**first == *state)
                return true;
            ++first;
        }
        return false;
    }

    bool closedContains(State<T> *state) {
        for (typename unordered_set<State<T> *>::iterator it = this->closed.begin();
             it != this->closed.end(); it++) {
            if (**it == *state) {
                return true;
            }
        }
        return false;
    }

    void updateStatePriority(State<T> *state) {
        if (this->opened.contains(state)) {
            auto t = this->opened.findIt(state);
            if ((*t)->getCost() > state->getCost()) {
                this->opened.remove(*t);
                this->opened.push(state);
            }
        }
    }
};

#endif //MAILSTONE2_ASTAR_H