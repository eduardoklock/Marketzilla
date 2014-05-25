#ifndef _LessItems_h_
#define _LessItems_h_

#include "dataStructures/CircularList.h"
#include "CashierPreference.h"

using dataStructures::CircularList;

namespace marketzilla{

class LessItems : public CashierPreference {
public: 
    Cashier& chooseCashier(CircularList<Cashier>&);

};

}

#endif