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
    //void eval(map<string,int> &T);
    void translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable);
    void insert(Stmt *T);
private:
    list<Stmt*> SL_;
};

#endif
