#ifndef _ShorterQueue_h_
#define _ShorterQueue_h_

#include "dataStructures/CircularList.h"
#include "CashierPreference.h"

using dataStructures::CircularList;

namespace marketzilla {

class ShorterQueue : public CashierPreference {
public:
    Cashier& chooseCashier(CircularList<Cashier>&);
};

}

#endif