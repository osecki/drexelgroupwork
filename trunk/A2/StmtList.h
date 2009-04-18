#ifndef STMTLIST_H
#define STMTLIST_H

#include <map>
#include <list>
#include <string>
#include "Stmt.h"

using namespace std;

class Proc;

class StmtList
{
public:
    StmtList() {};

    void eval(map<string,int> &NT, map<string,Proc*> &FT)
    {
        list<Stmt*>::iterator Sp;
        for (Sp = SL_.begin();Sp != SL_.end();Sp++)
	      (*Sp)->eval(NT,FT);
    }

    void insert(Stmt *T)
    {
        SL_.push_front(T);
    }

private:
    list <Stmt*> SL_;
};

#endif

