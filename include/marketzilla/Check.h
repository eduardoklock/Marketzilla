#ifndef _Check_h_
#define _Check_h_

#include "Payment.h"

namespace marketzilla{

class Check : public Payment {
public:
	double delay() const;
};

}

#endif