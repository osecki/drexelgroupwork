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

void StmtList::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable)
{
	for (list<Stmt*>::iterator Sp = SL_.begin(); Sp != SL_.end(); Sp++)
		(*Sp)->translate(constantValues, symbolTable);
}
