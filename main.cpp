#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

        cout << "Markte Name: "<< marketName << endl;
        cout << "Simulation Time: " << timeOfSimulation << endl;
        cout << "Clients arraival Delay: " <<timeOfClientsArive <<endl;
        cout << "Number of Cashiers: "<< numberOfCashiers << endl;

        int salary;
        int eficiency;
        string name;
        for(int i = 0; i < numberOfCashiers; ++i)
        {
            file >> name;
            file >> eficiency;
            file >> salary;
            //market.add(Cashier(name,salary,eficiency));
            cout << "Cashier: " << name << " " << eficiency << " " << salary << endl;
        }

        file.close();
    }
    else
    {
        cout << "file not finded" << endl;
    }

    //Market market = Market(marketName, timeOfSimulation, timeOfClientsArive);
    //Market.simulate();
    
    return 0;
}