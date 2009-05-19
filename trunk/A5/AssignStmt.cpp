#include <map>
#include "Proc.h"
#include "AssignStmt.h"

AssignStmt::AssignStmt(string name, Expr *E)
{
	name_ = name;
	E_ = E;
}

// Changed environment table here
void AssignStmt::eval(map<string,Element*> &NT) const
{
	// Change name table
	NT[name_] = E_->eval(NT);
	
	// if the expression is Proc type then set the current environment
	if (STATIC && dynamic_cast<Proc*>(E_)) {
		// Now set the environment 
		((Proc*)E_)->setTheEnvironment(&NT);
		
		// Update name table with this new Proc
		NT[name_] = E_->eval(NT);
	}
}
