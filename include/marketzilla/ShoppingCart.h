#ifndef _ShoppingCart_h_
#define _ShoppingCart_h_

#include <stdlib.h>

namespace marketzilla{

class ShoppingCart {
public:
	ShoppingCart();
	~ShoppingCart();
	int retrunTotalItems() const;
	double returnTotalValue() const;
private:
	int totalItems;
	double totalValue;

	void generateItems();
	void generateValue();
};
}
#endif