#ifndef STMTLIST_H
#define STMTLIST_H

#include <map>
#include <string>
#include <list>
#include "Stmt.h"

using namespace std;

class Proc;

class StmtList
{
public:
    StmtList() {};
		// Changed environment table here
    void eval(map<string,Element*> &NT, map<string,Proc*> &FT);
    void insert(Stmt *T);

private:
    list<Stmt*> SL_;
};

#endif
