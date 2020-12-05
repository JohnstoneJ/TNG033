/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/

#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>
using namespace std;

#include "expression.h"

class Logarithm : public Expression
{

public:

	// Default constructor that creates the logarithm log2x
	Logarithm();

	// A constructor that given an expression i and constants c1, 
	// c2 and b creates the logarithmic expressino c1+c2*logb(E)
	Logarithm(const Expression & E, double C1, double C2, int B);

	// Copy constructor
	Logarithm(const Logarithm& L);

	//Destructor
	virtual ~Logarithm();

	// An assignment operator= 
	Logarithm& operator=(const Logarithm& i);

	//calculate y if x is d
	virtual double operator()(double d)const override;

	// Virutal function - display 
	virtual void display(ostream &os)const override;

	virtual Logarithm * clone() const override;
	
protected:
	double c1, c2;
	int b;
	Expression *e;

};

#endif
