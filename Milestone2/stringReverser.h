#ifndef MAILSTONE2_STRINGREVERSER_H
#define MAILSTONE2_STRINGREVERSER_H


#include <string>
#include <algorithm>
#include "Solver.h"

using namespace std;

template<class P, class S>
class stringReverser : public Solver<string, string> {
public:
    stringReverser() = default;
    string solve(string problem);
};

template<class P, class S>
string stringReverser<P, S>::solve(string problem) {
    reverse(problem.begin(), problem.end());
    return problem;
}

#endif //MAILSTONE2_STRINGREVERSER_H
