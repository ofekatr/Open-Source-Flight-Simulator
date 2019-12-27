#ifndef PROJECT_DATAREADERSERVER_H
#define PROJECT_DATAREADERSERVER_H
#include "thread"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "Command.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include "SymbolTable.h"
#include "BIndingTable.h"
#include "dictionaryPath.h"
#define FLIGHT_PARAMETERS 23
static vector<string> pathVector{"instrumentation/airspeed-indicator/indicated-speed-kt",
                                         "instrumentation/altimeter/indicated-altitude-ft",
                                         "instrumentation/altimeter/pressure-alt-ft",
                                         "instrumentation/attitude-indicator/indicated-pitch-deg",
                                         "instrumentation/attitude-indicator/indicated-roll-deg",
                                         "instrumentation/attitude-indicator/internal-pitch-deg",
                                         "instrumentation/attitude-indicator/internal-roll-deg",
                                         "instrumentation/encoder/indicated-altitude-ft",
                                         "instrumentation/encoder/pressure-alt-ft",
                                         "instrumentation/gps/indicated-altitude-ft",
                                         "instrumentation/gps/indicated-ground-speed-kt",
                                         "instrumentation/gps/indicated-vertical-speed",
                                         "instrumentation/heading-indicator/indicated-heading-deg",
                                         "instrumentation/magnetic-compass/indicated-heading-deg",
                                         "instrumentation/slip-skid-ball/indicated-slip-skid",
                                         "instrumentation/turn-indicator/indicated-turn-rate",
                                         "instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                         "controls/flight/aileron",
                                         "controls/flight/elevator",
                                         "controls/flight/rudder",
                                         "controls/flight/flaps",
                                         "controls/engines/current-engine/throttle",
                                         "engines/engine/rpm"};
using namespace std;
class DataReaderServer {
public:
    static vector<string> splitByComma(char *buffer);
    // object function.
    void operator()(int port, int hertz);
    // update the data
    static void updateData();
    // initialize the map of the dictonary.
    static void initializeDictionaryMap(vector<string> vector);
};


#endif //PROJECT_DATAREADERSERVER_H
