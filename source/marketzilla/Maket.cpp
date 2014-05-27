#include <string>
#include <iostream>

#include "marketzilla/Market.h"
#include "marketzilla/ClientFactory.h"

namespace marketzilla {

Market::Market(const string& marketName, int totalSimulationTime, int arrivalTimeCliet):
    marketName(marketName),
    totalSimulationTime(totalSimulationTime),
    arrivalTimeCliet(arrivalTimeCliet),
    currentTime(0),
    givenUpClients(0),
    totalInjury(0),
    cashiers()
{}

void Market::addCashiers(const Cashier& cashier)
{
    cashiers.push_back(cashier);
}

bool Market::allQueueEmpty()
{
    for (auto &i : cashiers){
        if(i.queueLength() != 0){
            return false;
        }
    }
    return true;
}

void Market::simulation()
{
    ClientFactory factory;
    while (currentTime < totalSimulationTime)
    {
        if(currentTime % arrivalTimeCliet == 0)
        {
            Client client = factory.makeClient(currentTime);
            if(!client.chooseCashier(cashiers))
            {
                ++givenUpClients;
                totalInjury = totalInjury + (client.totalItemsValue()*3); 
            }

        }

        for (auto &i : cashiers)
        {
            i.update(currentTime);
        }
        ++currentTime;
    }

    while(!allQueueEmpty())
    {
        for (auto &i : cashiers)
        {
            i.update(currentTime);
        }
        ++currentTime;
    }

    for (auto i : cashiers)
    {
        std::cout << i.attendantName() << " :" << std::endl ;
        std::cout << "  servedClients : " << i.clientsServed() << std::endl;
        //std::cout << "  queueLength : " << i.queueLength() << std::endl;
        std::cout << "  averageWaitingTime : " << i.averageWaitingTime() << std::endl;
        std::cout << "  totalProfit : " << i.totalProfit() << std::endl;
        std::cout << "  averageProfit : " << i.averageProfit() << std::endl;
    }

    std::cout << "givenUpClients: " << givenUpClients << std::endl;   
}

}