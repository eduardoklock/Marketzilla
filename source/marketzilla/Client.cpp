#include <marketzilla/Client.h>

namespace marketzilla{

Client::Client(ShoppingCart cart):
cart(cart)
{
    if(rand() % 5 == 0)
    {
        payment = new Check();
    }
    else
    {
        payment = new Cash();
    }
}

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