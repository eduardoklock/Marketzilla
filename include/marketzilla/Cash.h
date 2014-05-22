#ifndef _Cahs_h_
#define _Cahs_h_

#include "Payment.h"

namespace marketzilla{

class Cash : public Payment {
public:
	double delay() const;
};

}

#endif