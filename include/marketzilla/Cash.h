#ifndef _Cahs_h_
#define _Cahs_h_

#include "Payment.h"

namespace marketzilla{

class Cash : public Payment {
public:
	Cash();
	~Cash();
	double delay() const;
};

}

#endif