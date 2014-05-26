#include <string>
#include "marketzilla/Cashier.h"

namespace marketzilla {

Cashier::Cashier(const std::string& name, double salary, int eficiency):
    _name(name),
    _salary(salary),
    _eficiency(eficiency),
    _queue(),
    _queueItems(0),
    _servedClients(0),
    _totalProfit(0),
    totalWaitingTime(0)
{}

Cashier::Cashier():
    _name(""),
    _salary(0),
    _eficiency(0),
    _queue(),
    _queueItems(0),
    _servedClients(0),
    _totalProfit(0),
    totalWaitingTime(0)
{}

void Cashier::update(int currentTime)
{
    if (_queue.isEmpty())
        return;
    const Client &firstClient = _queue.front();
    if (firstClient.exitTime() == currentTime) {
        ++_servedClients;
        //totalWaitingTime += currentTime - firstClient.timeOfArrival();
        _totalProfit += firstClient.totalItemsValue();
        _queueItems -= firstClient.totalItems();
        _queue.pop();
    }
}

std::string Cashier::attendantName() const
{
    return _name;
}

double Cashier::attendantSalary() const
{
    return _salary;
}

int Cashier::attendantEficiency() const
{
    return _eficiency;
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