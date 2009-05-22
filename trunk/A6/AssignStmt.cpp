#include <map>
#include "AssignStmt.h"

AssignStmt::AssignStmt(string name, Expr *E)
{
	name_ = name;
	E_ = E;
}

void AssignStmt::eval(map<string,int> &NT) const
{
	// Change name table
	NT[name_] = E_->eval(NT);
}
