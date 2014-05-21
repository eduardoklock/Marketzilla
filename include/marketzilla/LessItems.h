#ifndef _LessItems_h_
#define _LessItems_h_

#include "CashierPreference.h"

namespace marketzilla{

class LessItems : public CashierPreference {
public: 
    void chooseQueue(const Market&);

};

}

#endif