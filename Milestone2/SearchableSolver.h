//
// Created by issa on 1/13/19.
//

#ifndef MAILSTONE2_SEARCHABLESOLVER_H
#define MAILSTONE2_SEARCHABLESOLVER_H

#include <iostream>
#include "Solver.h"
#include "ISearcher.h"
#include "ISearchable.h"
#include "matrix.h"

//template<class S, class T>
class SearchableSolver : public Solver<matrix, vector<string>> {
    ISearcher<vector<State<pair<int, int>>*>,pair<int,int>> *searcher;
public:
    SearchableSolver(ISearcher<vector<State<pair<int, int>>*>,pair<int,int>> * search){
        this->searcher = search;
    }
    vector<string> solve(matrix* problem){
        vector<State<pair<int, int>>*> v = this->searcher->search(problem);
        cout << "Nodes " << this->searcher->getNumberOfNodesEvaluated() << endl;
        cout << "Cost " << this->searcher->getShortestCost() << endl;
        vector<string> vStr;
        vector<State<pair<int, int>>*>::iterator father;
        for (vector<State<pair<int, int>>*>::iterator current = v.begin();
        current != v.end() && father != v.end(); current++){
            father = current;
            father++;
            if (father == v.end())
                break;
            double pfirst = (*father)->getState().first, psecond = (*father)->getState().second;
            double sfirst = (*current)->getState().first, ssecond = (*current)->getState().second;
            if (pfirst < sfirst){
                vStr.push_back("up");
            }
            else if (pfirst > sfirst){
                vStr.push_back("down");
            }
            else if (psecond < ssecond){
                vStr.push_back("left");
            }
            else if (psecond > ssecond){
                vStr.push_back("right");
            }
            else {
                throw "Invalid path - A state does not change.";
            }
        }
        return vStr;
    }
    ~SearchableSolver(){

    }

};


#endif //MAILSTONE2_SEARCHABLESOLVER_H
