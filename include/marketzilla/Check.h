#ifndef _Check_h_
#define _Check_h_

#include "Payment.h"
#include "Cashier.h"

namespace marketzilla{

class Check : public Payment {
public:
	Check();
	~Check();
	double addTime(Cashier&) const;
private:

};

}

#endif