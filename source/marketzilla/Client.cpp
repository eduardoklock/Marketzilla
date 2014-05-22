#include "marketzilla/Client.h"

namespace marketzilla{

Client::Client(const ShoppingCart& cart, Payment* payment, CashierPreference* preference):
cart(cart),
payment(payment),
preference(preference)
{}

Client::~Client()
{}

Payment* Client::makePayment() const
{
    return payment;
}

ShoppingCart Client::passShopping() const
{
    return cart;
}

}