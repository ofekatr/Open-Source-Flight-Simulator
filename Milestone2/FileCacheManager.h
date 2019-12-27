//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_FILECACHEMANAGER_H
#define MAILSTONE2_FILECACHEMANAGER_H


#include <unordered_map>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include "CacheManger.h"
#include "StringConvert.h"
#include <map>
#include <iostream>
#include <mutex>

#define space " "

template<class Problem, class S>
class FileCacheManager : public CacheManger<Problem, S> {
    // map for mapping problems to solutions in vector<string> formats.
    map<vector<string>, vector<string>> problemsAndSolutions;
    // a converter for matrixes and their solution.
    StringConvert<Problem, S> *convert;
public:
    // Constructor.
    FileCacheManager(StringConvert<Problem, S> *convert) {
        this->convert = convert;
        this->loadMap();
    }

    //Checking if solution exists in the map.
    virtual bool isSolutionExist(Problem &problem);

    //Getting the solution of a given problem from a file.
    virtual vector<string> getSolutionString(Problem& problem);

    //Saving a solution in the map and in the file.
    virtual void saveSolution(Problem& problem, S& solution);

    //Loads all problems and solutions.
    void loadMap();

    //Saves a problem and a solution on the file in vector<string> format.
    void saveOnFile(const vector<string> &problem, const vector<string> &solution);

    //Splits a string to vector of strings using ',' character.
    vector<string> splitValues(const string &line);

    ~FileCacheManager() {
        delete this->convert;
    }
};

template<class P, class S>
bool FileCacheManager<P, S>::isSolutionExist(P& problem) {
    return this->problemsAndSolutions.count(this->convert->ProblemToString(problem)) != 0;
}

template<class P, class S>
vector<string> FileCacheManager<P, S>::getSolutionString(P &problem) {
    cout << "get the Solution" << endl;
    vector<string> problemRepresentByString = this->convert->ProblemToString(problem);
    auto it = problemsAndSolutions.find(problemRepresentByString);
    if (it != problemsAndSolutions.end()) {
        if (it->first == problemRepresentByString) {
            return it->second;
        }
    }
    //return NULL;
}

template<class P, class S>
void FileCacheManager<P, S>::saveSolution(P& problem, S& solution) {
    vector<string> problemRepresentByString = this->convert->ProblemToString(problem);
    vector<string> solutionRepresentByString = this->convert->solutionToString(solution);
    this->problemsAndSolutions[problemRepresentByString] = solutionRepresentByString;
    saveOnFile(problemRepresentByString, solutionRepresentByString);
}

template<class P, class S>
void FileCacheManager<P, S>::loadMap() {
    ifstream solutions("solutionToProblem.txt");
    string line;
    vector<string> p, s;
    while (getline(solutions, line)) {
        do {
            p.push_back(line);
        } while (getline(solutions, line) && (line != "@EndOfProblem@"));
        while (getline(solutions, line) && (line != "$EndOfSolution$"))
            s.push_back(line);
    }
    this->problemsAndSolutions.insert(make_pair(p, s));
}

template<class P, class S>
void FileCacheManager<P, S>::saveOnFile(const vector<string> &problem, const vector<string> &solution) {
    ofstream sol;
    sol.open("solutionToProblem.txt", ios::app);
    for (string str : problem) {
        sol << str << endl;
    }
    sol << "@EndOfProblem@" << endl;
    for (string str : solution) {
        sol << str << endl;
    }
    sol << "$EndOfSolution$" << endl;
    sol.close();
}

template<class P, class S>
vector<string> FileCacheManager<P, S>::splitValues(const string &line) {
    //function to split the line by spaces.
    stringstream ss(line);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    return vstrings;
}

#endif //MAILSTONE2_FILECACHEMANAGER_H
