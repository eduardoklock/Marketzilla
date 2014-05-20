#include <marketzilla/Cashier.h>
#include <string>

using std::string;

namespace marketzilla {

Cashier::Cashier(const string& name, const double& salary):
    _name(name),
    _salary(salary)
{}

string Cashier::name() const 
{
    return _name;
}

double Cashier::salary() const 
{
    return _salary;
}

}