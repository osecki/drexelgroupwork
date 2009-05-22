#ifndef WHILESTMT_H
#define WHILESTMT_H

#include <map>
#include <string>
#include "StmtList.h"
#include "Stmt.h"
#include "Expr.h"
using namespace std;

class WhileStmt: public Stmt
{
public:
    WhileStmt(Expr *E, StmtList *S);
    ~WhileStmt();
    void eval(map<string,int> &NT) const;
private:
    Expr* E_;
    StmtList *S_;
};

#endif
