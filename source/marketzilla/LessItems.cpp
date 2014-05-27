#include <algorithm>

#include "dataStructures/CircularList.h"
#include "marketzilla/LessItems.h"
#include "marketzilla/Cashier.h"

using dataStructures::CircularList;

namespace marketzilla{

Cashier& LessItems::chooseCashier(CircularList<Cashier>& cashiers)
{
    // auto j = cashiers.begin();
    // auto i = cashiers.begin();
    // auto cashier = *i;
    // while(i != cashiers.end())
    // {
    //     ++j;
    //     if(i.queueItems() > j.queueItems())
    //     {
    //         cashier = j;
    //     }
    //     ++i;
  
    // }

    // //for (auto &i , &j : )

    // return cashier;

    auto a = std::min_element(begin(cashiers), end(cashiers), [](const Cashier &a, const Cashier &b)
    {
        return a.queueItems() < b.queueItems();
    });

    return *a;
}

}