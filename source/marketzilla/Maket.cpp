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
    finalProfit(0),
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
        std::cout << "  Served Clients: " << i.clientsServed() << std::endl;
        std::cout << "  Average Waiting Time: " << i.averageWaitingTime() << std::endl;
        std::cout << "  Total Cashier Profit: " << i.totalProfit() << std::endl;
        std::cout << "  Profit less salary: " << i.totalProfit() - i.attendantSalary() << std::endl;
        finalProfit = finalProfit + i.totalProfit();
        std::cout << "  Aerage Cashier Profit : " << i.averageProfit() << std::endl;
    }

    std::cout << "\nGiven Up Clients: " << givenUpClients << std::endl;  
    std::cout << "Total Profit: " << finalProfit << std::endl;
    std::cout << "Total Injury: " << totalInjury << std::endl;
}

}