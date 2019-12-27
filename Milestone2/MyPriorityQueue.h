
//
// Created by jokereed on 1/11/19.
//

#ifndef MAILSTONE2_MYPRIORITYQUEUE_H
#define MAILSTONE2_MYPRIORITYQUEUE_H


#include <queue>
#include <algorithm>
#include "State.h"


template<class T, class toComapre>
class MyPriorityQueue : public std::priority_queue<T, std::vector<T>, toComapre> {
private:

public:

    void remove(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return;
        }
        return;
    }

    /*
    bool contains(T value) {
        typename std::vector<T>::iterator it = std::find(this->c.begin(), this->c.end(), value);
        return it != this->c.end();
    }
    */
    bool contains(T value) {
        for (auto i : this->c) {
            if (i->getState() == value->getState())
                return true;
        }
        return false;
    }

    typename std::vector<T>::iterator findIt(T value) {
        for (typename std::vector<T>::iterator it = this->c.begin(); it != this->c.end(); it++) {
            if ((**it) == *value)
                return it;
        }
    }

    std::vector<T> getContainer() {
        return this->c;
    }

};


#endif //MAILSTONE2_MYPRIORITYQUEUE_H