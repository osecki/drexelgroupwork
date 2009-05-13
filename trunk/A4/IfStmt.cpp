#include "IfStmt.h"
#include "StmtList.h"
#include "Proc.h"
#include "Expr.h"
#include "Number.h"
#include <map>

IfStmt::IfStmt(Expr *E, StmtList *S1, StmtList *S2)
{
  E_ = E;
  S1_ = S1;
  S2_ = S2;
}

IfStmt::~IfStmt() { delete E_; delete S1_; delete S2_; }

// Changed environment table here
void IfStmt::eval(map<string,Element*> &NT) const
{
	Element* e = E_->eval(NT);
	if(dynamic_cast<Number*>(e)) {
	    if (((Number*)e)->getValue() > 0) {
	        S1_->eval(NT);
	    } else {
	        S2_->eval(NT);
	    }
	} else {
		cout << "ERROR: Conditional does not evaluate to a numeric value" << endl;
		exit(1);
	}
}
