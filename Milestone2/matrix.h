
#ifndef MAILSTONE2_MATRIX_H
#define MAILSTONE2_MATRIX_H

#include <map>
#include <queue>
#include "ISearchable.h"
#include <ostream>
class matrix : public ISearchable<pair<int, int>> {
private:
    pair<int, int> source, goal;
    int height;
    int width;
    int **arr;
    vector<State<pair<int, int>> *> theTrash;
public:
    matrix(int **arr, int height, int width, pair<int, int> source, pair<int, int> goal) : arr(arr), height(height),
                                                                                           width(width), source(source),
                                                                                           goal(goal) {}

    pair<int, int> getSource() {
        return this->source;
    }

    int getWidth() {
        return this->width;
    }

    int getHeight() {
        return this->height;
    }

    int **getArr() {
        return this->arr;
    }

    State<pair<int, int>> *getInitialState() {
        State<pair<int, int>> *startState = new State<pair<int, int>>(make_pair(0, 0));
        startState->setCost(arr[0][0]);
        theTrash.push_back(startState);
        return startState;
    }

    bool isGoalState(State<pair<int, int>> *state) {
        // the lower-bottom cell's coordinates.
        pair<int, int> goal = make_pair(this->height - 1, this->width - 1);
        // pairs comparison.
        return state->getState() == goal;
    }

    vector<State<pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *state) {
        vector<State<pair<int, int>> *> states;
        // i, j coordinates.
        int i = state->getState().first, j = state->getState().second;
        // Down.
        if (i != this->height - 1 && arr[i + 1][j] >= 0) {
            State<pair<int, int>> *down = new State<pair<int, int>>(make_pair(i + 1, j));
            down->setCost(this->arr[i + 1][j] + state->getCost());
            this->setHeuristic(down);
            states.push_back(down);
        }
        // Up.
        if (i != 0 && arr[i - 1][j] >= 0) {
            State<pair<int, int>> *up = new State<pair<int, int>>(make_pair(i - 1, j));
            up->setCost(this->arr[i - 1][j] + state->getCost());
            this->setHeuristic(up);
            states.push_back(up);
        }
        // Right.
        if (j < width - 1 && arr[i][j + 1] > -1) {
            State<pair<int, int>> *right = new State<pair<int, int>>(make_pair(i, j + 1));
            right->setCost(this->arr[i][j + 1] + state->getCost());
            this->setHeuristic(right);
            states.push_back(right);
        }
        // Left.
        if (j != 0 && arr[i][j - 1] >= 0) {
            State<pair<int, int>> *left = new State<pair<int, int>>(make_pair(i, j - 1));
            left->setCost(this->arr[i][j - 1] + state->getCost());
            this->setHeuristic(left);
            states.push_back(left);
        }
        // Set the pie.
        for (vector<State<pair<int, int>> *>::iterator it = states.begin(); it != states.end(); it++) {
            (*it)->setcameFrom(state);
            //theTrash.push_back(*it);
        }
        return states;

    }

    pair<int, int> getGoal() {
        return this->goal;
    }

    void setHeuristic(State<pair<int, int>> *state) {
        pair<double, double> current = state->getState();
        state->setHeuristic((abs(current.first - this->goal.first) + abs(current.second - this->goal.second)));
    }

    ~matrix() {
        for (int i = 0; i < this->height; i++) {
            delete[] this->arr[i];
        }
        delete[] arr;
        for (auto &it : theTrash) {
            delete it;
        }
    }
};

#endif //MAILSTONE2_MATRIX_H
