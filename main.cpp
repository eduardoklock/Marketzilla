#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

#include "marketzilla/Market.h"
#include "marketzilla/Cashier.h"

using namespace std;

using marketzilla::Market;
using marketzilla::Cashier;

string readInput(fstream& file) {
    string input;
    do {
        getline(file, input);
        input = input.substr(input.find_first_not_of(' '),
                input.find_first_of('#'));
    } while (input.empty());
    return input;
}

int main(int argc, char** argv)
{
    if(argc == 1){
        string marketName;
        int timeOfSimulation;
        int timeOfClientsArive;
        int numberOfCashiers;

        
        cout << "insert market name: " << endl;
        getline(cin, marketName);
        cout << "insert simulation time: " << endl;
        cin >> timeOfSimulation;
        cout << "insert clients interval arraival time: " << endl;
        cin >> timeOfClientsArive;
        cout << "insert number of cashiers: " << endl;
        cin >> numberOfCashiers;

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
            cout << "insert cashier name: " << endl;
            cin >> name;
            cout << "insert cashier eficiency: " << endl;
            cin >> eficiency;
            cout << "insert cashier salary: " << endl;
            cin >> salary;

            market.addCashiers(Cashier{name, salary, eficiency});
            cout << "Cashier: " << name << " " << eficiency << " " << salary << " added."<<  endl;
        }

        market.simulation();
        cout << marketName << endl;   
    }
    else if(argc == 3 && !strcmp("-f",argv[1]))
    {
        string marketName;
        int timeOfSimulation;
        int timeOfClientsArive;
        int numberOfCashiers;
        fstream file;
        file.open(argv[2]);

        if(file.is_open())
        {
            stringstream(readInput(file)) >> marketName;
            stringstream(readInput(file)) >> timeOfSimulation;
            stringstream(readInput(file)) >> timeOfClientsArive;
            stringstream(readInput(file)) >> numberOfCashiers;

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
                stringstream(readInput(file)) >> name >> eficiency >> salary;
                
                market.addCashiers(Cashier{name, salary, eficiency});
                cout << "Cashier: " << name << " " << eficiency << " " << salary << endl;
            }

            file.close();

            market.simulation();
            cout << marketName << endl;   
        }
        else
        {
            cout << "file not finded" << endl;
        }
    }
    else if (!strcmp("--help",argv[1]))
    {
        cout << "use -f <name_of_data_file>" << endl;
    }


    
    return 0;
}