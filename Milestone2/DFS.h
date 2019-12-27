//
// Created by issa on 1/5/19.
//

#ifndef MAILSTONE2_DFS_H
#define MAILSTONE2_DFS_H


#include <stack>
#include "Searcher.h"
#include "ISearchable.h"
//#include "StackSearcher.h"


template<class S, class T>
class DFS : public Searcher<S, T> {
    stack<State<T> *> opened;
public:
    S search(ISearchable<T>* searchable){
        this->NumberOfNodesEvaluated = 0;
        // Add the initial to opened.
        this->addToOpenList(searchable->getInitialState());
        while (!this->opened.empty()){
            // pop from opened.
            State<T> *n = this->popOpenList();
            // if n was not checked before.
            if (!this->closedContains(n)) {
                // Backtrace if goal is found.
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
                }
                    // Else, open n's successors.
                else{
                    for(State<T> *s: searchable->getAllPossibleState(n)){
                        this->addToOpenList(s);
                    }
                }
                // close n.
                this->closed.insert(n);
            }
        }
        // Could not find a path.
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
        for (State<T> * it : this->opened) {
            if (**it == *state) {
                return true;
            }
        }
        return false;
    }
    bool closedContains(State<T> *state){
        for (typename unordered_set<State<T> *>::iterator it = this->closed.begin(); it != this->closed.end(); it++) {
            if (**it == *state) {
                return true;
            }
        }
        return false;
    }
};


#endif //MAILSTONE2_DFS_H