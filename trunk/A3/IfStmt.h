#ifndef IFSTMT_H
#define IFSTMT_H

#include <map>
#include <string>
#include "StmtList.h"
#include "Stmt.h"
#include "Expr.h"
#include "ConsCell.h"

class Proc;
//class Expr;
//class StmtList;
//class ConsCell;


using namespace std;

class IfStmt: public Stmt
{
public:
    IfStmt(Expr *E,StmtList *S1, StmtList *S2);
    ~IfStmt();
		// Changed environment table here
    void eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const;
private:
    Expr* E_;
    StmtList* S1_;
    StmtList* S2_;
};

#endif
