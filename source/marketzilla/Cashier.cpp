#include <marketzilla/Cashier.h>

namespace marketzilla {

Cashier::Cashier(const Attendant& attendant):
    _attendant(attendant)
{}

int Cashier::queueItems() const
{
    return 0;
}

int Cashier::queueLength() const
{
    return _queue.size();
}

void Cashier::enterQueue(const Client& client)
{
    _queue.push(client);
}


}