#ifndef _Client_h_
#define _Client_h_

#include "dataStructures/CircularList.h"

#include "ShoppingCart.h"
#include "Payment.h"
#include "CashierPreference.h"

using dataStructures::CircularList;

namespace marketzilla{

class Client {
public:
	Client(const ShoppingCart&, Payment*, CashierPreference*);
	~Client();

    void choseCashier(const CircularList<Cashier>&);

	Payment* makePayment() const;
	ShoppingCart passShopping() const;
private:
	ShoppingCart cart;
	Payment* payment;
    CashierPreference* preference;
    
};
}
#endif