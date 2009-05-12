#include "StmtList.h"
#include "Stmt.h"
#include <map>

void StmtList::insert(Stmt * S)
{
 	SL_.push_front(S);
}

// Changed environment table here
void StmtList::eval(map<string,Element*> &NT)
{
  	list<Stmt*>::iterator Sp;
  	for (Sp = SL_.begin();Sp != SL_.end();Sp++) {
    	(*Sp)->eval(NT);
	}
}
