#ifndef _Payment_h_
#define _Payment_h_

#include "Cashier.h"

namespace marketzilla{

class Payment {
public:
	virtual double addTime(Cashier&) const = 0;
private:

};

}

#endif