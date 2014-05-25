#include "dataStructures/CircularList.h"
#include "marketzilla/ShorterQueue.h"
#include "marketzilla/Cashier.h"

using dataStructures::CircularList;

namespace marketzilla{

Cashier& ShorterQueue::chooseCashier(CircularList<Cashier>& cashiers)
{

    auto j = cashiers.begin();
    auto i = cashiers.begin();
    Cashier& cashier = *i;
    while(i != cashiers.end())
    {
        ++j;
        if(i->queueLength() > j->queueLength())
        {
            Cashier& cashier = *j;
        }
        ++i;
  
    }

    return cashier;

}

}