#ifndef IFSTMT_H
#define IFSTMT_H

#include <map>
#include <string>
#include "StmtList.h"
#include "Stmt.h"
#include "Expr.h"
using namespace std;

class IfStmt: public Stmt
{
public:
    IfStmt(Expr *E, StmtList *S1, StmtList *S2);
    ~IfStmt() {delete E_;};
    void translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const;
private:
    Expr* E_;
    StmtList *S1_;
    StmtList *S2_;
};

#endif
