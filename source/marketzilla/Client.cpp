#include "marketzilla/Client.h"
#include "marketzilla/Cashier.h"

namespace marketzilla{

Client::Client(Payment* payment, CashierPreference* preference, int _totalItems, double _totalItemsValue):
payment(payment),
preference(preference),
_totalItems(_totalItems),
_totalItemsValue(_totalItemsValue)
{}

Client::~Client()
{
    //delete payment;
    //delete preference;
}

bool Client::chooseCashier(CircularList<Cashier>& cashiers) 
{

    auto i = cashiers.begin();
    while(i != cashiers.end())
    {
        if(i->queueLength() < 10)
        {
            preference->chooseCashier(cashiers).enterQueue(*this);
            return true;
        }
        ++i;
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

void Client::setExitTime(int _exitTime)
{
    _exitTime = _exitTime;
}

}