#ifndef _Market_h_
#define _Market_h_

#include "Cashier.h"

namespace marketzilla {

class Market{
public:
    Market(string, int, int, CircularList<Cashier>*);
    void creatCashiers(const string&, double, int);
    void simulation();
    bool allQueueEmpty();
	
private:
    CircularList<Cashier>* cashiers;
    int currentTime;
    int givenUpClients;
    int totalInjury;
    int totalSimulationTime;
    int arrivalTimeCliet;
    string marketName;

};

}
#endif