
#ifndef MAILSTONE2_SOLVER_H
#define MAILSTONE2_SOLVER_H

template <class P,class S>
class Solver{
public:
    virtual S solve(P* problem) = 0;
};
#endif //MAILSTONE2_SOLVER_H
