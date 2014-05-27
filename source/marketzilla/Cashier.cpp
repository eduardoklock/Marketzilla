#include <string>
#include <iostream>
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
{
    if(_eficiency == 3)
    {
        _eficiency++;
    }
}

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
    if (_queue.isEmpty()){
        return;
    } 

    const Client &firstClient = _queue.front();
    if (firstClient.exitTime() == currentTime) {
        ++_servedClients;
        totalWaitingTime += currentTime - firstClient.arrivalTime();
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
    return ((double)totalWaitingTime)/_servedClients;
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

void Cashier::enterQueue(Client& client)
{
    _queueItems += client.totalItems();

    int auxTime = client.arrivalTime() + _eficiency*client.totalItems();

    if(_eficiency == 1){
        auxTime += 10*client.makePayment()->delay();
    }
    else if(_eficiency == 2){
        auxTime += 25*client.makePayment()->delay();
    }
    else if(_eficiency == 4){
        auxTime += 60*client.makePayment()->delay();
    }

    if(!_queue.isEmpty()) {
        auxTime += _queue.back().exitTime();
    }

    client.setExitTime(auxTime);

    _queue.push(client);
}

}