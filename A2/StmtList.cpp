#include "StmtList.h"
#include "Stmt.h"
#include <map>

void StmtList::insert(Stmt * S)
{
  SL_.push_front(S);
}

void StmtList::eval(map<string,int> &NT, map<string,Proc*> &FT)
{
  list<Stmt*>::iterator Sp;
  for (Sp = SL_.begin();Sp != SL_.end();Sp++)
    (*Sp)->eval(NT,FT);
}
