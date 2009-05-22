#include "StmtList.h"
#include "Stmt.h"
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

void StmtList::insert(Stmt * S)
{
 	SL_.push_front(S);
}

void StmtList::eval(map<string,int> &NT) {
  	for (list<Stmt*>::iterator Sp = SL_.begin(); Sp != SL_.end(); Sp++) {
    	(*Sp)->eval(NT);
	}
}
