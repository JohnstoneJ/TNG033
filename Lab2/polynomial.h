/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"

class Polynomial : public Expression
{								

public: 

	// Default constructor 
	Polynomial();	

	// Constructor that creates a polynomial from an array of doubles
	Polynomial(int N_terms, double Coeffs[]);

	// Constructor that creates a polynomial from a double
	//a conversion constructor to convert a real constant into a polynomial
	Polynomial(double x);
	
	// Virtual function - Display expression 
	virtual void display(ostream &os)const override;

	//Copy constructor
	Polynomial(const Polynomial& P);

	//Destructor
	virtual ~Polynomial(); 

	//A subscript operator that can be used to access the value of a polynomial´s coefficient

	//double& operator[](const int d)const;

	double& operator[]( int d);

	const double& operator[]( int d) const;

	//MARTIN
	// pp[2] = 3.3; should not compile- ingen ändring ska ske

	//Assignment operator
	Polynomial& operator=(Polynomial p);

	//calculate y if x is d
	virtual double operator()(double d)const override;

	// Operator+. Polynomial + Polynomial 
	Polynomial operator+(const Polynomial& p)const;
	
	// Operator+. Polynomial + double 
	Polynomial operator+(double d)const;

	virtual Polynomial* clone() const override;

protected:
	int degree;
	double* Coeff;

};

 // Operator+. double + Polynomial. Not a member function (friend) 
Polynomial operator+(double d, const Polynomial & p);



#endif
