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

		// Changed environment table here
    virtual void eval(map<string,Element*> &NT) const;

private:
    Expr* E_;
    StmtList *S_;
};

#endif
