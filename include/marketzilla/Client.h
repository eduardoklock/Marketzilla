#ifndef _Client_h_
#define _Client_h_

#include "ShoppingCart.h"
#include "Cash.h"
#include "Check.h"
#include <stdlib.h>

namespace marketzilla{

class Client {
public:
	Client(ShoppingCart);
	~Client();
	Payment* makePayment() const;
	ShoppingCart passShopping() const;
private:
	ShoppingCart cart;
	Payment* payment;
    
};
}
#endif