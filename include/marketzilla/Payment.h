#ifndef _Payment_h_
#define _Payment_h_

namespace marketzilla{

class Payment {
public:
	virtual double delay() const = 0;
};

}

#endif