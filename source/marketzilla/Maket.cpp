#include "marketzilla/Market.h"
#include "marketzilla/ClientFactory.h"
#include <string>


namespace marketzilla {

Market::Market(string marketName,int totalSimulationTime, int arrivalTimeCliet):
marketName(marketName),
totalSimulationTime(totalSimulationTime),
arrivalTimeCliet(arrivalTimeCliet),
currentTime(0),
givenUpClients(0),
totalInjury(0)
{
    cashiers = new CircularList<Cashier>;
}

void Market::addCashiers(Cashier& cashier)
{
    cashiers->push_back(cashier);
}

bool Market::allQueueEmpty()
{
    return true;
}

void Market::simulation()
{
    ClientFactory factory = ClientFactory();
    while(currentTime != totalSimulationTime && allQueueEmpty())
    {
        if(currentTime % arrivalTimeCliet == 0 && currentTime < totalSimulationTime)
        {
            Client client = factory.makeClient();
            if(!client.chooseCashier(*cashiers))
            {
                ++givenUpClients;
                totalInjury = totalInjury + (client.totalItemsValue()*3);
            }
            else
            {
                //calculo do cashier para setar tempo de saida....
            }
        }
        auto i = cashiers->begin();
        while(i != cashiers->end())
        {
            i->update(currentTime);
            ++i;
        }
        ++currentTime;

    }
}


}