#include <string>
#include "marketzilla/Cashier.h"

namespace marketzilla {

Cashier::Cashier(const Attendant& attendant):
    _attendant(attendant),
    _queue(),
    _queueItems(0),
    _servedClients(0),
    _totalProfit(0),
    totalWaitingTime(0)
{}

Cashier::Cashier():
    _attendant("", 0.0, 0),
    _queue(),
    _queueItems(0),
    _servedClients(0),
    _totalProfit(0),
    totalWaitingTime(0)
{}

void Cashier::update(int curretTime)
{

}

const std::string Cashier::attendantName() const
{
    return _attendant.name();
}

double Cashier::averageWaitingTime() const
{
    return totalWaitingTime/_servedClients;
}

int Cashier::clientsServed() const
{
    return _servedClients;
}

double Cashier::totalProfit() const
{
    return _totalProfit;
}

double Cashier::averageProfit() const
{
    return _totalProfit/_servedClients;
}

int Cashier::queueItems() const
{
    return _queueItems;
}

int Cashier::queueLength() const
{
    return _queue.size();
}

void Cashier::enterQueue(const Client& client)
{
    _queueItems += client.totalItems();
    _queue.push(client);
}

}