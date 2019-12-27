cmake_minimum_required(VERSION 3.12)
project(mailStone2)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")
set(CMAKE_CXX_STANDARD 14)

add_executable(mailStone2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.h Solver.h CacheManger.h FileCacheManager.cpp FileCacheManager.h State.h ISearchable.h ISearcher.h BestFirstSerch.cpp BestFirstSerch.h Searcher.h DFS.cpp DFS.h stringReverser.h BFS.cpp BFS.h Astar.cpp Astar.h matrix.h StringConvert.h ConnectionManager.cpp ConnectionManager.h MyPriorityQueue.h Comparators.h Coordinates.h Splitter.cpp Splitter.h matrixClientHandler.h MyParllelServer.cpp MyParllelServer.h SearchableSolver.cpp SearchableSolver.h matrixConvert.h ArgumentForServer.h)
