#ifndef _Attendant_h_
#define _Attendant_h_

#include <string>

using std::string;

namespace marketzilla {

class Attendant {
public:
    Attendant(const string&, double, int);
    const string name() const;
    double salary() const;
    int eficiency() const;
private:
    string _name;
    double _salary;
    int _eficiency;
};

}

#endif