#include <marketzilla/Check.h>

namespace marketzilla{

Check::Check()
{}

Check::~Check()
{}

double Check::delay() const
{
	/*
		depende da eficiencia do caixa, se ruim retorna
		6, medio 2,5, bom 1

	*/
		return 10;
}

}