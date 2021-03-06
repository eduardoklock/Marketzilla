#ifndef _Check_h_
#define _Check_h_

#include "Payment.h"

namespace marketzilla{

class Check : public Payment {
public:
    ~Check();

/**
 * @brief Retorna o atraso quando se paga com cheque
 */
	double delay() const;
};

}

#endif