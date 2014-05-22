#include <marketzilla/ClientFactory.h>

namespace marketzilla{

Client& ClientFactory::makeClient()
{
    ShoppingCart cart = ShoppingCart();
    Payment* payment;
    CashierPreference* preference;
    if(rand() % 5 == 0)
    {
        Payment* payment = new Cash();
    }
    else
    {
        Payment* payment = new Check();
    }
    if(rand() % 2 == 0)
    {
        CashierPreference* preference = new ShorterQueue();
    }
    else
    {
        CashierPreference* preference = new LessItems();
    }
    Client client = Client(cart, payment, preference);

    return client;
}

}