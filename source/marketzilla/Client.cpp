#include <marketzilla/Client.h>


namespace marketzilla{

Client::Client(ShoppingCart cart):
cart(cart)
{}

Client::~Client()
{}

double Client::payment()
{

	return cart.returnTotalValue();
}

int Client::totalItems()
{
	return cart.retrunTotalItems();
}

}