#include <marketzilla/Client.h>


namespace marketzilla{

Client::Client(ShoppingCart cart, Payment payment):
cart(cart)
payment(payment)
{}

Client::~Client()
{}

Client::makePayment() const
{
    return payment;
}

Client::passShopping() const
{
    return cart;
}

}