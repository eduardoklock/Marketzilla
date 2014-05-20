#ifndef _Cashier_h_
#define _Cashier_h_

#include <string>

using std::string;

namespace marketzilla {

class Cashier {
public:
    Cashier(const string&, const double&);
    string name() const;
    double salary() const;
private:
    string _name;
    double _salary;
};

}

#endif