#include "marketzilla/ClientFactory.h"
#include "marketzilla/Cash.h"
#include "marketzilla/Check.h"
#include "marketzilla/ShorterQueue.h"
#include "marketzilla/LessItems.h"
#include <stdlib.h>

namespace marketzilla{

Client ClientFactory::makeClient(int currentTime)
{
    Payment* payment;
    CashierPreference* preference;
    int _totalItems;
    double _totalItemsValue;
    if(rand() % 5 == 0)
    {
        payment = new Cash();
    }
    else
    {
        payment = new Check();
    }
    if(rand() % 2 == 0)
    {
        preference = new ShorterQueue();
    }
    else
    {
        preference = new LessItems();
    }

    _totalItems = rand() % 99 + 2;
    

 
    for(int i = 0; i < _totalItems; i++)
    {
        _totalItemsValue = _totalItemsValue + rand() % 90 + 1;      
    }

    return Client(payment, preference, _totalItems, _totalItemsValue, currentTime);
}

}