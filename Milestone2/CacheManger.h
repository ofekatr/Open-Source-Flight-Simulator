//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_CACHEMANGER_H
#define MAILSTONE2_CACHEMANGER_H

#include <string>
#include <vector>
using namespace std;
template <class P,class S>
class CacheManger {
public:
    // Checks if the solution exists in the cache.
    virtual bool isSolutionExist(P& problem) = 0;
    // Returns the solution to the given problem from the cache.
    virtual vector<string> getSolutionString(P& problem) = 0;
    // Save the solution in the cache.
    virtual void saveSolution(P& problem, S& solution) = 0;

    virtual ~CacheManger(){

    }
};


#endif //MAILSTONE2_CACHEMANGER_H
