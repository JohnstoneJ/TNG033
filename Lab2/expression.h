/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
using namespace std;

const double EPSILON = 1.0e-5;

//BASE CLASS. ABSTRACT CLASS (have one (or more) pure virtual functions)

class Expression
{

public: 
    

	//Default destructor 
	virtual ~Expression() = default;

	//Pure virtual function
	virtual double operator()(double d) const = 0;

	//test whether a given value 𝑥 is a root of the function f
	bool isroot(double d) const;   

	//Pure virtual function
	virtual Expression* clone() const = 0;

	// to display an expression
	friend ostream& operator<<(ostream& os, const Expression& E);

	
protected: 

	//Default constructor 
	Expression() = default;
	
	//Copy constructor
	Expression(const Expression&) = delete;

	//Assignment opertor
	Expression& operator=(const Expression& e) = delete;

	//Pure virtual function
	virtual void display(ostream &os) const = 0; 

};


#endif