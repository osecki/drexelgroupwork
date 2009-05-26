#ifndef WHILESTMT_H
#define WHILESTMT_H

#include <map>
#include <vector>
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
    void translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const;
private:
    Expr* E_;
    StmtList *S_;
};

#endif
