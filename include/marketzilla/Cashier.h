#ifndef _Cashier_h_
#define _Cashier_h_

#include <string>

#include "dataStructures/Queue.h"

#include "Client.h"

using dataStructures::Queue;

namespace marketzilla {

class Cashier {
public:
    Cashier(const std::string&, double, int);

    Cashier();

    std::string attendantName() const;
    double attendantSalary() const;
    int attendantEficiency() const;

    int clientsServed() const;
    double averageWaitingTime() const;

    double totalProfit() const;
    double averageProfit() const;

    int queueItems() const;
    int queueLength() const;
    void enterQueue(const Client&);

    void update(int);

private:
    std::string _name;
    double _salary;
    int _eficiency;

    Queue<Client> _queue;
    int _queueItems;
    int _servedClients;
    double _totalProfit;
    int totalWaitingTime;
};

}

#endif