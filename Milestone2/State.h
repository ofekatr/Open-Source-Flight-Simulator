//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_STATE_H
#define MAILSTONE2_STATE_H

template<class T>
class State {
    T state;
    double cost;
    double heuristic;
    State<T> *cameFrom = nullptr;
public:
    State(T State) : state(State) {}

    void setcameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;

    }

    bool operator==(const State<T> &state) {
        return this->state == state.state;
    }

    T getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

    State<T> *getFather() const {
        return cameFrom;
    }

    void setCost(double cost) {
        this->cost = cost;
    }
    void setHeuristic(double h){
        this->heuristic = h;
    }
    double getHeuristic(){
        return this->heuristic;
    }
};


#endif //MAILSTONE2_STATE_H
