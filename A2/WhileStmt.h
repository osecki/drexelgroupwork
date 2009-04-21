#ifndef WHILESTMT_H
#define WHILESTMT_H

#include <map>
#include <string>
#include "StmtList.h"
#include "Stmt.h"
#include "Expr.h"

class Proc;

using namespace std;

class WhileStmt: public Stmt
{
public:
    WhileStmt(Expr *E,StmtList *S);

    ~WhileStmt();

    virtual void eval(map<string,int> &NT, map<string,Proc*> &FT) const;

private:
    Expr* E_;
    StmtList *S_;
};

#endif
