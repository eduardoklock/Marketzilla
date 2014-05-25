#ifndef _Cashier_h_
#define _Cashier_h_

#include <string>

#include "dataStructures/Queue.h"

#include "Attendant.h"
#include "Client.h"

using dataStructures::Queue;

namespace marketzilla {

class Cashier {
public:
    Cashier(const Attendant&);

    Cashier();

    const std::string attendantName() const;

   	int clientsServed() const;

   	double totalProfit() const;
   	double averageProfit() const;

    int queueItems() const;
    int queueLength() const;
    void enterQueue(const Client&);

    void update(int);

private:
    Attendant _attendant;
    Queue<Client> _queue;
    int _queueItems;
    int _servedClients;
    double _totalProfit;
};

}

#endif