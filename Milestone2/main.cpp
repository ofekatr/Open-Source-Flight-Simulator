#include <iostream>
#include "Solver.h"
#include "ISearchable.h"
#include "Server.h"
#include "MySerialServer.h"
#include "matrixConvert.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "stringReverser.h"
#include "matrix.h"
#include "ISearcher.h"
#include "BestFirstSerch.h"
#include "BFS.h"
#include "DFS.h"
#include "Astar.h"
#include "MyParllelServer.h"
#include "SearchableSolver.h"
//#include "Searcher.h"
//template <class p,class solution>

int main(int argc, char* argv[]) {
    int port = 5400;
    StringConvert<matrix,vector<string>> *convert = new matrixConvert();
    server_side::Server *s = new MyParllelServer();
    CacheManger<matrix,vector<string>> *cacheManger = new FileCacheManager<matrix,vector<string>>(convert);
    ISearcher<vector<State<pair<int, int>>*>,pair<int,int>> *algorithm = new Astar<vector<State<pair<int, int>>*>,pair<int,int>>();
    Solver<matrix,vector<string>> *solver = new SearchableSolver(algorithm);
    ClientHandler *c = new MyTestClientHandler<matrix,vector<string>>(solver,cacheManger);
    s->open(port, c);
    delete s;
    delete cacheManger;
    delete solver;

}