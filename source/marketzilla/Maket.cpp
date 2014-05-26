#include "marketzilla/Market.h"
#include "marketzilla/ClientFactory.h"
#include <string>


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
    auto i = cashiers.begin();
    while(i != cashiers.end())
    {
        if(i->queueLength() != 0)
        {
            return false;
        }
    }
    return true;
}

void Market::simulation()
{
    ClientFactory factory = ClientFactory();
    while(currentTime < totalSimulationTime)
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
        auto i = cashiers.begin();
        while(i != cashiers.end())
        {
            i->update(currentTime);
            ++i;
        }
        ++currentTime;

    }
    while(!allQueueEmpty())
    {
        auto i = cashiers.begin();
        while(i != cashiers.end())
        {
            i->update(currentTime);
            ++i;
        }
    }
}


}