#include "marketzilla/Client.h"
#include "marketzilla/Cashier.h"

#include <iostream>

namespace marketzilla{

Client::Client(Payment* payment, CashierPreference* preference, int _totalItems, double _totalItemsValue, int _arrivalTime):
payment(payment),
preference(preference),
_totalItems(_totalItems),
_totalItemsValue(_totalItemsValue),
_arrivalTime(_arrivalTime)
{}

Client::~Client()
{}

bool Client::chooseCashier(CircularList<Cashier>& cashiers) 
{

    for (auto &i : cashiers)
    {
        if(i.queueLength() < 10)
        {
            preference->chooseCashier(cashiers).enterQueue(*this);
            return true;
        }
    }
    return false;
}

Payment* Client::makePayment() const
{
    return payment;
}

int Client::totalItems() const
{
    return _totalItems;
}

double Client::totalItemsValue() const
{
    return _totalItemsValue;
}

int Client::exitTime() const
{
    return _exitTime;
}

void Client::setExitTime(int exitTime)
{
    _exitTime = exitTime;
}

int Client::arrivalTime() const
{
    return _arrivalTime;
}

}