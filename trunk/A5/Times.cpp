#include "Times.h"
#include "Expr.h"
#include "Number.h"
#include <map>

Times::Times(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

// Changed environment table here and casted it to be a "Number"
Element* Times::eval(map<string,Element*> &NT) const
{
	Element* e1 = op1_->eval(NT);
	Element* e2 = op2_->eval(NT);
	if(dynamic_cast<Number*>(e1) && dynamic_cast<Number*>(e2)) { 
    	return new Number(((Number*)e1)->getValue() * ((Number*)e2)->getValue());
	}
	
	cout << "ERROR: Tried to multiply non-numbers" << endl;
	exit(1); 
}
