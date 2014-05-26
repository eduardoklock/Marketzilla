#ifndef _Market_h_
#define _Market_h_

#include <string>

#include "Cashier.h"

using std::string;

namespace marketzilla {

class Market{
public:
    Market(const string&, int, int);
    void addCashiers(Cashier&);
    void simulation();
    bool allQueueEmpty();
	
private:
    CircularList<Cashier> cashiers;
    int currentTime;
    int givenUpClients;
    int totalInjury;
    int totalSimulationTime;
    int arrivalTimeCliet;
    string marketName;

};

}
#endif