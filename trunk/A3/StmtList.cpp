#include "StmtList.h"
#include "Stmt.h"
#include "Program.h"
#include <map>


void StmtList::insert(Stmt * S)
{
  SL_.push_front(S);
}

// Changed environment table here
void StmtList::eval(map<string,Element*> &NT, map<string,Proc*> &FT, Memory &memory)
{
    list<Stmt*>::iterator Sp;
    int statement = 1;
    for (Sp = SL_.begin();Sp != SL_.end();Sp++) {
        (*Sp)->eval(NT,FT,memory);
        if(DEBUG) {
            cout << "Memory table after statement " << statement++ << endl;
            memory.output();
        }
    }
}
