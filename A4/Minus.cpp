#include "Minus.h"
#include "Expr.h"
#include "Number.h"
#include <map>

Minus::Minus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

// Changed environment table here and cast it to be a "Number"
Element* Minus::eval(map<string,Element*> &NT) const
{
	Element* e1 = op1_->eval(NT);
	Element* e2 = op2_->eval(NT);
	if(dynamic_cast<Number*>(e1) && dynamic_cast<Number*>(e2)) { 
    	return new Number(((Number*)e1)->getValue() - ((Number*)e2)->getValue());
	}
	
	cout << "ERROR: Tried to subtract non-numbers" << endl;
	exit(1); 
}
