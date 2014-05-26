#include <iostream>
#include <fstream>
#include <string>

#include "marketzilla/Market.h"
#include "marketzilla/Cashier.h"

using namespace std;

using marketzilla::Market;
using marketzilla::Cashier;

int main(int argc, char** argv)
{
    string marketName;
    int timeOfSimulation;
    int timeOfClientsArive;
    int numberOfCashiers;
    fstream file;
    file.open("data");

    if(file.is_open())
    {
        getline(file, marketName);
        file >> timeOfSimulation;
        file >> timeOfClientsArive;
        file >> numberOfCashiers;

        timeOfSimulation *= 3600; 

        cout << "Market Name: "<< marketName << endl;
        cout << "Simulation Time: " << timeOfSimulation << " seconds" << endl;
        cout << "Clients arraival Delay: " << timeOfClientsArive << " seconds" << endl;
        cout << "Number of Cashiers: "<< numberOfCashiers << endl;

        Market market{marketName, timeOfSimulation, timeOfClientsArive};

        double salary;
        int eficiency;
        string name;
        for(int i = 0; i < numberOfCashiers; ++i)
        {
            file >> name;
            file >> eficiency;
            file >> salary;
            market.addCashiers(Cashier{name, salary, eficiency});
            cout << "Cashier: " << name << " " << eficiency << " " << salary << endl;
        }

        file.close();

        market.simulation();
    }
    else
    {
        cout << "file not finded" << endl;
    }

    
    
    return 0;
}