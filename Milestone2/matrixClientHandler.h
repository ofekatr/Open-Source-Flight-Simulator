    }
//
// Created by issa on 1/13/19.
//

#ifndef MAILSTONE2_MATRIXCLIENTHANDLER_H
#define MAILSTONE2_MATRIXCLIENTHANDLER_H

#include "ClientHandler.h"
#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "Splitter.h"

template<class P, class S>
class matrixClientHandler : public ClientHandler {
    unsigned long row, colm, counter;
    Splitter splitter;
    Solver<P, S> *solver;
    CacheManger<P, S> *cacheManger;
public:
    matrixClientHandler(Solver<P, S> *solve, CacheManger<P, S> *cacheManger) {
        this->solver = solve;
        this->cacheManger = cacheManger;
    }

    void handleClient(ConnectionManager *connectionManager) override;
};

template<class P, class S>
void matrixClientHandler<P, S>::handleClient(ConnectionManager *connectionManager) {
    vector<vector<int>> valuesOfMatrix;
    vector<int> matrixByLine;
    vector<string> valuesOfLine;
    pair<int,int> enterInState;
    pair<int,int> exitInState;
    string line;
    //this->cacheManger->loadMap();
    line = connectionManager->readLine();
    while (line != "end\r\n") {
        if (line == "end") {
            break;
        }
        valuesOfLine = this->splitter.splitBy(line);
        this->colm = valuesOfLine.size();
        for (const auto &i : valuesOfLine) {
            matrixByLine.push_back(stoi(i));
        }
        valuesOfLine.clear();
        valuesOfMatrix.push_back(matrixByLine);
        matrixByLine.clear();
        line = connectionManager->readLine();
        counter++;
    }
    exitInState = make_pair(valuesOfMatrix[counter-1][0],valuesOfMatrix[counter-1][1]);
    enterInState = make_pair(valuesOfMatrix[counter-2][0],valuesOfMatrix[counter-2][1]);
    if (cacheManger->isSolutionExist(line)) {
        connectionManager->sendLine(cacheManger->getSolutionString(line));
    } else if (!line.empty()) {
        S solution = this->solver->solve(line);
        this->cacheManger->saveSolution(line, solution);
        connectionManager->sendLine(solution);
    }
}
#endif //MAILSTONE2_MATRIXCLIENTHANDLER_H
