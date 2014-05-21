#ifndef _CashierPreference_h_
#define _CashierPreference_h_

#include "Market.h"

namespace marketzilla{

class CashierPreference {
public:
    virtual void chooseQueue(const Market&) = 0;

};

}

#endif