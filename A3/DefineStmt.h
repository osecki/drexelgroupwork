#ifndef DEFINESTMT_H
#define DEFINESTMT_H

#include <map>
#include <string>
#include "Stmt.h"
#include "Expr.h"
#include "ConsCell.h"
#include<vector>

class Proc;

using namespace std;

class DefineStmt : public Stmt
{
public:
    DefineStmt(string name="", Proc *P=NULL);
    virtual ~DefineStmt();
		// Changed environment table here
		virtual void eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const;
private:
    string name_;
    Proc* P_;
};

#endif
