/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

#include <iomanip>

//ADD implementation of the member functions for class Logarithm

// Default constructor 
Logarithm::Logarithm()
{
	c1 = 0.0;
	c2 = 1.0;
	b = 2;
	double Coeff[2] = { 0, 1 }; // x
	e = new Polynomial(1, Coeff); //new polynomial with degree 1 => x
}

// Constructor
Logarithm::Logarithm(const Expression& E, double C1, double C2, int B)
{
	e = E.clone();
	c1 = C1; 
	c2 = C2; 
	b = B; 
}


// Copy constructor
Logarithm::Logarithm(const Logarithm& L)  
{
	c1 = L.c1; 
	c2 = L.c2; 
	b = L.b; 
	e = L.e->clone();  
}

//Destructor
Logarithm::~Logarithm()
{
	/*c1 = 0.0;
	c2 = 0.0;
	b = 0;*/

	delete e;
	
	//e = nullptr;
}

// Assingment operator= 
Logarithm & Logarithm::operator=(const Logarithm& i) //MARTIN
{
	//Logarithm temp = Logarithm(i);

/*	std::swap(c1,temp.c1);
	std::swap(c2, temp.c2);
	std::swap(b, temp.b);
	std::swap(e,temp.e);
	*/
	c1 = i.c1;
	c2 = i.c2;
	b = i.b;
	delete e;
    e = i.e->clone();

	return *this; 

}

//calculate y if x is d
double Logarithm::operator()(double d) const
{
	double y = 0;
	y = c1 + c2 *( log10((*e)(d)) / log10(b));
	return y;
}

// Virutal function - display 
void Logarithm::display(ostream & os) const
{
	if (c1 == 0)
	{
		os << fixed<<setprecision(2)<< c2 << "*Log_" << b << "(" << *e << ")";
	}
	else {
		os << fixed << setprecision(2) << c1 << "+" << c2 << "*Log_" << b << "(" << *e << ")";
	}
}

//Clone
Logarithm* Logarithm::clone()const {
	return new Logarithm{*this};
}
