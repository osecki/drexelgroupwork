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
	
	while(1) {
		Element* e = E_->eval(NT);
		if(dynamic_cast<Number*>(e)) {
			if(((Number*)e)->getValue() > 0) {
        		S_->eval(NT);
			} else { 
    			return;
			}
		} else {
			cout << "ERROR: Conditional of while does not evaluate to a numeric value" << endl;
			exit(1);
		}
	}
}
