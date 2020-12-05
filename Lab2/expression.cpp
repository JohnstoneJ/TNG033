/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"
#include <math.h> 

//test whether a given value 𝑥 is a root of the function f
bool Expression::isroot(double x) const {

	//abs- absolutbelopp 
	if (abs((*this)(x)) < EPSILON)
	{
		return true;
	}
	return false;
}

//to display an expression (lec. 10 slide 26)
ostream& operator<<(ostream& os, const Expression& E) {

	E.display(os); 
	
	return os;
}

