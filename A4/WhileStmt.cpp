#include <map>
#include "Proc.h"
#include "WhileStmt.h"
#include "Expr.h"
#include "Number.h"

WhileStmt::WhileStmt(Expr *E, StmtList *S)
{
  E_ = E;
  S_ = S;
}

WhileStmt::~WhileStmt() { delete E_; delete S_; }

// Changed environment table here
void WhileStmt::eval(map<string,Element*> &NT) const
{
	Element* e = E_->eval(NT);
	if(dynamic_cast<Number*>(e)) {
    	while (((Number*)e)->getValue() > 0) {
        	S_->eval(NT);
    	}
	} else {
		cout << "ERROR: Conditional of while does not evaluate to a numeric value" << endl;
		exit(1);
	}
}
