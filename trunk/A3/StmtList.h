#ifndef STMTLIST_H
#define STMTLIST_H

#include <map>
#include<vector>
#include <string>
#include <list>
#include "Stmt.h"
#include "ConsCell.h"

using namespace std;

class Proc;

class StmtList
{
public:
    StmtList() {};
		// Changed environment table here
    // Changed environment table to hold the listmemory and listmemory available pointer
    void eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail);
    void insert(Stmt *T);

private:
    list<Stmt*> SL_;
};

#endif
