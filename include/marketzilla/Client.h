#ifndef _Client_h_
#define _Client_h_

#include "dataStructures/CircularList.h"

#include "Payment.h"
#include "CashierPreference.h"

using dataStructures::CircularList;

namespace marketzilla{

class Client {
public:
	Client(Payment*, CashierPreference*, int, double);
	~Client();

    bool chooseCashier(CircularList<Cashier>&);
	Payment* makePayment() const;
    int totalItems() const;
    double totalItemsValue() const;
    int exitTime();
    void setExitTime(int);

private:
	Payment* payment;
    CashierPreference* preference;
    int _totalItems;
    double _totalItemsValue;
    int _exitTime;
    
    
};
}
#endif
