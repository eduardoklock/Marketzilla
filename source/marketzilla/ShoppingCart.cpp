#include <marketzilla/ShoppingCart.h>

namespace marketzilla{

ShoppingCart::ShoppingCart()
{
	generateItems();
	generateValue();
}

ShoppingCart::~ShoppingCart(){}

void ShoppingCart::generateItems()
{
	totalItems = rand() % 99 + 2;
}

void ShoppingCart::generateValue()
{
	for(int i = 0; i < totalItems; i++)
	{
		totalValue = totalValue + rand() % 90 + 1;
		
	}	
}

int ShoppingCart::retrunTotalItems()
{
	return totalItems;
}

double ShoppingCart::returnTotalValue()
{
	return totalValue;
}

}