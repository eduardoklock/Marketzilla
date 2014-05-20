#ifndef _Cashiers_h_
#define _Cashiers_h_

class Cashiers {
public:

private:
	String name;
	Queue<Client>* clients;
	Efficiency efficiency; //fazer um enum
	double salary;

}