#include "StmtList.h"
#include "Stmt.h"
#include <map>

#include "ConsCell.h"
#include<vector>


void StmtList::insert(Stmt * S)
{
  SL_.push_front(S);
}

// Changed environment table here
void StmtList::eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail)
{
  list<Stmt*>::iterator Sp;
  for (Sp = SL_.begin();Sp != SL_.end();Sp++) {
    (*Sp)->eval(NT,FT,listMemory,avail);
    }
}
