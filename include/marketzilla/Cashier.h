#ifndef _Cashier_h_
#define _Cashier_h_

#include "dataStructures/Queue.h"

#include "Attendant.h"
#include "Client.h"

using dataStructures::Queue;

namespace marketzilla {

class Cashier {
public:
    Cashier(const Attendant&);

    int queueItems() const;

    int queueLength() const;

    void enterQueue(const Client&);

private:
    Attendant _attendant;
    Queue<Client> _queue;
};

}

#endif