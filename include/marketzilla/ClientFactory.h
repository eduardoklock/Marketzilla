#ifndef _ClientFactory_h_
#define _ClientFactory_h_

#include "Client.h"

namespace marketzilla {

class ClientFactory {
public:
    static Client& makeClient() const;

};

}

#endif