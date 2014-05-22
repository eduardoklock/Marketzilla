#include "marketzilla/ClientFactory.h"
#include "marketzilla/Cash.h"
#include "marketzilla/Check.h"
#include "marketzilla/ShorterQueue.h"
#include "marketzilla/LessItems.h"
#include <stdlib.h>

namespace marketzilla{

Client ClientFactory::makeClient()
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

    return Client(cart, payment, preference);
}

}