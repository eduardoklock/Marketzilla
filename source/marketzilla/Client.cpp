#include <marketzilla/Client.h>


namespace marketzilla{

Client::Client(ShoppingCart cart, Payment* payment):
cart(cart),
payment(payment)
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