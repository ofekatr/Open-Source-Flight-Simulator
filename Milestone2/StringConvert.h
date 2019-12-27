//
// Created by issa on 1/7/19.
//

#include <string>

#ifndef MAILSTONE2_STRINGCONVECRTOR_H
#define MAILSTONE2_STRINGCONVECRTOR_H

using namespace std;

template<class Problem, class Solution>
class StringConvert {
public:
    virtual vector<string> ProblemToString(Problem& problem) = 0;

    virtual Problem stringToProblem(const vector<string> &problem) = 0;

    virtual vector<string> solutionToString(Solution solution) = 0;

    virtual Solution stringToSolution(const vector<string> &problem) = 0;
};

#endif //MAILSTONE2_STRINGCONVECRTOR_H
