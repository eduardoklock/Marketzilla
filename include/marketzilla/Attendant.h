#ifndef _Attendant_h_
#define _Attendant_h_

#include <string>

using std::string;

namespace marketzilla {

class Attendant {
public:
    Attendant(const string&, const double&);
    string name() const;
    double salary() const;
private:
    string _name;
    double _salary;
};

}

#endif