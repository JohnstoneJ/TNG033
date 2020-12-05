/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"
#include <iomanip>
//DERIVED class- SUB

//Default contructor
Polynomial::Polynomial()
{
	degree = 0; 
	Coeff = new double[degree+1];
}

//Copy constructor - deep copy 
Polynomial::Polynomial(const Polynomial& P) : degree{P.degree}, Coeff{new double[P.degree+1]} {
	
	for (int i = 0; i <= degree; i++) {
		Coeff[i] = P.Coeff[i];
	}

}

//Destructor
Polynomial::~Polynomial()
{	
	delete[] Coeff;
	Coeff = nullptr;
	degree = 0;
}

// Constructor that creates a polynomial from an array of doubles
Polynomial::Polynomial(int N_terms, double Coeffs[])  {

	degree = N_terms; 
	Coeff = new double[degree+1];

	for (int i = 0; i < degree+1; i++) {

		Coeff[i] = Coeffs[i]; 
	}

}
// Polynom från start dvs x^0
//a conversion constructor to convert a real constant into a polynomial
Polynomial::Polynomial(double x) 
{
	degree = 0;
	Coeff = new double(x);

	//Coeff = new double[1];
	//Coeff[0] = x;

}

//display the Polynom  
void Polynomial::display(ostream& os)const
{
	for (int i = 0; i <= degree; i++)
	{
		if (abs(Coeff[i]) > EPSILON)
		{
			if (i == 0)
			{
				os << fixed << setprecision(2) << Coeff[i];
	
			}
			else
			{
				os	<< fixed << setprecision(2) << " + " << Coeff[i] << " * x^" << i;
			}
		}
		
	}
}

double& Polynomial::operator[]( int d)
{
	return Coeff[d];
}

//A subscript operator that can be used to access the value of a polynomial´s coefficient
const double& Polynomial::operator[]( int d) const
{
	return Coeff[d];
}

// Assignment operator, swapfunktion. p = polynom
 Polynomial& Polynomial::operator=( Polynomial p) 
{
	 Polynomial temp = Polynomial(p);

	std::swap(Coeff, temp.Coeff); 
	std::swap(degree, temp.degree);

	return *this; 
}
  
 //Good programming practice! Use reference parameters (T&) when overloading operators for your data type T /Aida 
 // Operator+. Polynomial + Polynomial 
 Polynomial Polynomial::operator+(const Polynomial& p) const
 {
	 //p = p2(rhs)

	 //temp = p1 (lhs)
	 Polynomial temp = Polynomial(*this);

	 for (int i = 0; i <= p.degree; i++)
	 {
		 temp.Coeff[i] += p.Coeff[i];
	 }
	 return temp;
 }

 // Operator+. Polynomial + double 
 Polynomial Polynomial::operator+(double d) const { //MARTIN
	
	 Polynomial temp = Polynomial(*this);

	 temp.Coeff[0] += d;

	// Coeff[0] += d; 

	 return(temp); 
 }

 // Operator+. double + Polynomial. Not a member function   
 Polynomial operator+(double d, const Polynomial & p)
 {
	 Polynomial answer(p);
	 answer[0] += d;
	 return answer;
 }

 //Clone - returns a pointer to a copy of this object 
 Polynomial* Polynomial::clone()const {
	 return new Polynomial{ *this };
 }

 //calculate y if x is d
 double Polynomial::operator()(double d) const
 {
	 double y = 0;

	 for(int i = 0; i < degree+1; i++)
	 {
		 y += Coeff[i] * pow(d, i);

	 }
	 return y;
 }
