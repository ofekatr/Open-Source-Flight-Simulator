//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_MYTESTCLIENTHANDLER_H
#define MAILSTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "Splitter.h"
#include "matrix.h"

template<class P, class S>
class MyTestClientHandler : public ClientHandler {
    Splitter splitter;
    Solver<P, S> *solver;
    CacheManger<P, S> *cacheManger;
    mutex mutexForLock;
public:
    MyTestClientHandler(Solver<P, S> *solve, CacheManger<P, S> *cacheManger) {
        this->solver = solve;
        this->cacheManger = cacheManger;
    }

    void handleClient(int sockfd) {
        ConnectionManager connectionManager(sockfd);
        unsigned long row, colm;
        unsigned long counter = 0;
        vector<vector<int>> valuesOfMatrix;
        vector<int> matrixByLine;
        vector<string> valuesOfLine;
        pair<int, int> enterInState;
        pair<int, int> exitInState;
        string line;
        line = connectionManager.readLine();
        while (line != "end\r\n") {
            if (line == "end") {
                break;
            }
            valuesOfLine = this->splitter.splitBy(line);
            for (auto &i : valuesOfLine) {
                while (i.at(0) == ' ')
                    i = i.substr(1);
                matrixByLine.push_back(stoi(i));
            }
            valuesOfLine.clear();
            valuesOfMatrix.push_back(matrixByLine);
            matrixByLine.clear();
            line = connectionManager.readLine();
            counter++;
        }
        colm = valuesOfMatrix[0].size();
        exitInState = make_pair(valuesOfMatrix[counter - 1][0], valuesOfMatrix[counter - 1][1]);
        enterInState = make_pair(valuesOfMatrix[counter - 2][0], valuesOfMatrix[counter - 2][1]);
        int **theMatrix = new int *[counter - 2];
        for (int i = 0; i < counter - 2; i++)
            theMatrix[i] = new int[colm];
        for (int i = 0; i < counter - 2; i++) {
            for (int j = 0; j < colm; j++) {
                int score = valuesOfMatrix[i][j];
                theMatrix[i][j] = valuesOfMatrix[i][j];
            }
        }
        auto *m = new matrix(theMatrix, counter - 2, colm, enterInState, exitInState);
        S solution = this->solver->solve(m);
        this->cacheManger->saveSolution(*m, solution);
        string str;
        for (auto &it : solution) {
            str += it + " ";
        }
        connectionManager.sendLine(str);
        //vector<string> solution = cacheManger->getSolutionString(*m);
        //string str;
        //for (auto &it : solution) {
          //  str += it;
            //if (it != *(solution.end()))
              //  str += " ";
        //}
        //connectionManager.sendLine(str);
        //mutexForLock.lock();
        /*
        if (cacheManger->isSolutionExist(*m)) {
        } else {
            S solution = this->solver->solve(m);
            this->cacheManger->saveSolution(*m, solution);
            string str;
            for (auto &it : solution) {
                str += it;
                if (it != *(--solution.end())) {
                    str += " ";
                }
            }
            connectionManager.sendLine(str);
        }
        mutexForLock.unlock();
         */
        delete m;
    }

    ~MyTestClientHandler() {
        delete solver;
        delete cacheManger;
    }
};


#endif //MAILSTONE2_MYTESTCLIENTHANDLER_H
