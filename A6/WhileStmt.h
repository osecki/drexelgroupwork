#ifndef WHILESTMT_H
#define WHILESTMT_H

#include <map>
#include <string>
#include "Stmt.h"
#include "Expr.h"
#include "StmtList.h"
using namespace std;

class WhileStmt: public Stmt
{
public:
    WhileStmt(Expr *E, StmtList *S);
    ~WhileStmt() {delete E_;};
    void eval(map<string,int> &T) const;
private:
    Expr* E_;
    StmtList *S_;
};

#endif
