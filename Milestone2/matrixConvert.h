//
// Created by issa on 1/13/19.
//

#ifndef MAILSTONE2_MATRIXCONVERT_H
#define MAILSTONE2_MATRIXCONVERT_H

#include <sstream>
#include "StringConvert.h"
#include "matrix.h"
#include "Splitter.h"

class matrixConvert : public StringConvert<matrix, vector<string>> {

    vector<string> ProblemToString(matrix &problem) {
        vector<string> v;
        ostringstream ss;
        int **arr = problem.getArr();
        for (int i = 0; i < problem.getHeight(); i++) {
            for (int j = 0; j < problem.getWidth(); j++) {
                if (j != 0)
                    ss << ", ";
                ss << arr[i][j];
            }
            v.push_back(ss.str());
            ss.str("");
            ss.clear();
        }
        ss<< problem.getSource().first << ", " << problem.getSource().second;
        v.push_back(ss.str());
        ss.str("");
        ss.clear();
        ss << problem.getGoal().first << ", " << problem.getGoal().second;
        v.push_back(ss.str());
        return v;
    }

    matrix stringToProblem(const vector<string> &problem) {
        vector<string> temp;
        Splitter splitter;
        int size = problem.size();
        pair<int, int> source, goal;
        int **arr = new int*[size - 2];
        temp = splitter.splitBy(problem[size - 1]);
        source = make_pair(stoi(temp[0]), stoi(temp[1]));
        temp = splitter.splitBy(problem[size - 2]);
        goal = make_pair(stoi(temp[0]), stoi(temp[1]));
        for (int i = 0; i <= size - 2; i++) {
            temp = splitter.splitBy(problem[i]);
            arr[i] = new int[temp.size()];
            for (int j = 0; j < temp.size(); j++)
                arr[i][j] = stoi(temp[j]);
        }
        return matrix(arr, size - 2, temp.size(), source, goal);
    }

    vector<string> solutionToString(vector<string> theSolution) {
        return theSolution;
    }

    vector<string> stringToSolution(const vector<string> &theSolution) {
        return theSolution;
    }

};

#endif //MAILSTONE2_MATRIXCONVERT_H
