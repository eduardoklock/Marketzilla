#ifndef _Client_h_
#define _Client_h_

#include "ShoppingCart.h"
#include "Cash.h"
#include "Check.h"
#include "LessItems.h"
#include "ShorterQueue.h"
#include <stdlib.h>

namespace marketzilla{

class Client {
public:
	Client(ShoppingCart, Payment*, CashierPreference*);
	~Client();
	Payment* makePayment() const;
	ShoppingCart passShopping() const;
private:
	ShoppingCart cart;
	Payment* payment;
    CashierPreference* preference;
    
};
}
#endif