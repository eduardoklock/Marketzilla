#include <marketzilla/Attendant.h>
#include <string>

using std::string;

namespace marketzilla {

Attendant::Attendant(const string& name, const double& salary):
    _name(name),
    _salary(salary)
{}

string Attendant::name() const 
{
    return _name;
}

double Attendant::salary() const 
{
    return _salary;
}

}