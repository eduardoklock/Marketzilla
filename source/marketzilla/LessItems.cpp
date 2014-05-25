#include "dataStructures/CircularList.h"
#include "marketzilla/LessItems.h"
#include "marketzilla/Cashier.h"

using dataStructures::CircularList;

namespace marketzilla{

Cashier& LessItems::chooseCashier(CircularList<Cashier>& cashiers)
{
    auto j = cashiers.begin();
    auto i = cashiers.begin();
    Cashier& cashier = *i;
    while(i != cashiers.end())
    {
        ++j;
        if(i->queueItems() > j->queueItems())
        {
            Cashier& cashier = *j;
        }
        ++i;
  
    }

    return cashier;
}

}