#ifndef ASSIGNSTMT_H
#define ASSIGNSTMT_H

#include <map>
#include <string>
#include <vector>
#include "Stmt.h"
#include "Expr.h"
using namespace std;

class AssignStmt: public Stmt
{
public:
    AssignStmt(string name="", Expr *E=NULL);
    ~AssignStmt() {delete E_;};
    void translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT) const;
private:
    string name_;
    Expr* E_;
};

#endif
