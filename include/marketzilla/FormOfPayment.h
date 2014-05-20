#ifndef _FormOfPayment_h_
#define _FormOfPayment_h_

#ifndef _Check_h_
#define _Check_h_

namespace marketzilla{

class FormOfPayment {
public:
	virtual int addTime(Cashier&) = 0;
	virtual double value() = 0;
private:

};

}

#endif