#ifndef _Client_h_
#define _Client_h_

#include "ShoppingCart.h"
#include "Payment.h"

namespace marketzilla{

class Client {
public:
	Client(ShoppingCart, Payment*);
	~Client();
	Payment* makePayment() const;
	ShoppingCart passShopping() const;
private:
	ShoppingCart cart;
	Payment* payment;
};
}
#endif