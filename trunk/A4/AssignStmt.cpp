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
	// if the expression is Proc type then set the current environment
	if (dynamic_cast<Proc*>(E_))
		((Proc*)E_)->setTheEnvironment(NT);
	NT[name_] = E_->eval(NT);
}
