#ifndef MAILSTONE2_SEARCHER_H
#define MAILSTONE2_SEARCHER_H

#include "ISearcher.h"
#include "State.h"
#include <queue>
#include <list>
#include <unordered_set>
#include <sstream>
#include <set>
#include <algorithm>

template<class S, class T>
class Searcher : public ISearcher<S, T> {
protected:
    unordered_set<State<T> *> closed;
    int NumberOfNodesEvaluated = 0;
    double shortestCost = 0;

public:
    Searcher() : NumberOfNodesEvaluated(0) {}

    virtual S search(ISearchable<T> *searchable) = 0;

    int getNumberOfNodesEvaluated() {
        return this->NumberOfNodesEvaluated;
    }
    double getShortestCost(){
        return this->shortestCost;
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
        for (typename multiset<State<T> *>::iterator it = this->opened.begin(); it != this->opened.end(); it++) {
            if (*it == state) {
                return true;
            }
        }
        return false;
    }

    S backtrace(State<T> *state) {
        this->shortestCost = state->getCost();
        S v = {state};
        State<T> *father;
        while ((state = state->getFather()) != NULL) {
            v.push_back(state);
        }
        std::reverse(v.begin(), v.end());
        return v;
    }
};
#endif //MAILSTONE2_SEARCHER_H