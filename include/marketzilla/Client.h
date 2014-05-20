#ifndef _Client_h_
#define _Client_h_

#include "ShoppingCart.h"

namespace marketzilla{

class Client {
public:
	Client(ShoppingCart){}
	~Client(){}
	double payment(){}
	int totalItems(){}

private:
	ShoppingCart cart;
};
}