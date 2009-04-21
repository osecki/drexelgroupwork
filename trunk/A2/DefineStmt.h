#ifndef DEFINESTMT_H
#define DEFINESTMT_H

#include <map>
#include <string>
#include "Stmt.h"
#include "Expr.h"

class Proc;

using namespace std;

class DefineStmt : public Stmt
{
public:
    DefineStmt(string name="", Proc *P=NULL);
    virtual ~DefineStmt();
    virtual void eval(map<string,Element*> &NT, map<string,Proc*> &FT) const;
private:
    string name_;
    Proc* P_;
};

#endif
