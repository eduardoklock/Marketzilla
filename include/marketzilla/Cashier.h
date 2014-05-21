#ifndef _Cashier_h_
#define _Cashier_h_

#include <dataStructures/Queue.h>

#include "Attendant.h"
//#include "Client.h"

using dataStructures::Queue;

namespace marketzilla {

class Cashier {
public:
    Cashier(const Attendant&);

private:
    Attendant attendent;
    //Queue<Client*> queue;
};

}

#endif