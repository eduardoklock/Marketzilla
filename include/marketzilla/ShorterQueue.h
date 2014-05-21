#ifndef _ShorterQueue_h_
#define _ShorterQueue_h_

#include "CashierPreference.h"

namespace marketzilla {

class ShorterQueue : public CashierPreference {
public:
    void chooseQueue(const Market&);

};

}

#endif