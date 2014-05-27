#include <algorithm>

#include "dataStructures/CircularList.h"
#include "marketzilla/ShorterQueue.h"
#include "marketzilla/Cashier.h"

using dataStructures::CircularList;

namespace marketzilla{

Cashier& ShorterQueue::chooseCashier(CircularList<Cashier>& cashiers)
{
    auto a = std::min_element(begin(cashiers), end(cashiers), [](const Cashier &a, const Cashier &b)
    {
        return a.queueLength() < b.queueLength();
    });

    return *a;
}

}