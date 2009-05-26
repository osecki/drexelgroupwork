#ifndef STMTLIST_H
#define STMTLIST_H

#include <map>
#include <string>
#include <list>
#include "Stmt.h"
using namespace std;

class StmtList
{
public:
    StmtList() {};
    void eval(map<string,int> &T);
    void insert(Stmt *T);
private:
    list<Stmt*> SL_;
};

#endif
