#ifndef STMTLIST_H
#define STMTLIST_H

#include <map>
#include <string>
#include <list>
#include "Stmt.h"
#include "Memory.h"

using namespace std;

class Proc;

class StmtList
{
public:
    StmtList() {};
		// Changed environment table here
    void eval(map<string,Element*> &NT, map<string,Proc*> &FT, Memory &memory);
    void insert(Stmt *T);

    void dumpNameTable(map<string,Element*> &NT, Memory &memory);

private:
    list<Stmt*> SL_;
};

#endif
