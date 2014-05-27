#ifndef _Cahs_h_
#define _Cahs_h_

#include "Payment.h"

namespace marketzilla{

class Cash : public Payment {
public:
    ~Cash();

/**
 * @brief Retorna o atraso quando se paga com dinheiro
 */
	double delay() const;
};

}

#endif