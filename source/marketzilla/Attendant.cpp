#include <marketzilla/Attendant.h>
#include <string>

using std::string;

namespace marketzilla {

Attendant::Attendant(const string& name, double salary, int eficiency):
    _name(name),
    _salary(salary),
    _eficiency(eficiency)
{}

string Attendant::name() const 
{
    return _name;
}

double Attendant::salary() const 
{
    return _salary;
}

int Attendant::eficiency() const
{
    return _eficiency;
}

}