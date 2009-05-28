#ifndef DEFINESTMT_H
#define DEFINESTMT_H

#include <map>
#include <string>
#include "Stmt.h"
#include "Expr.h"
using namespace std;

class Proc;

class DefineStmt : public Stmt
{
public:
    DefineStmt(string name="", Proc *P=NULL);
    virtual ~DefineStmt();
    virtual void translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const;
private:
    string name_;
    Proc* P_;
};

#endif
