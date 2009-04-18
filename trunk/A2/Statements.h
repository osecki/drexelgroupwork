#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <map>
#include <string>
#include "Stmt.h"
#include "Expr.h"

class Proc;

class AssignStmt: public Stmt
{
public:
    AssignStmt(string name="", Expr *E=NULL)
    {
        name_ = name;
        E_ = E;
    }

    ~AssignStmt() {delete E_;}

    void eval(map<string,int> &NT, map<string,Proc*> &FT) const
    {
	NT[name_] = E_->eval(NT,FT);
    }

private:
    string name_;
    Expr* E_;
};


class DefineStmt : public Stmt
{
public:
    DefineStmt(string name="", Proc *P=NULL)
    {
         name_ = name;
         P_ = P;
    }

    virtual ~DefineStmt() {delete P_;}

    virtual void eval(map<string,int> &NT, map<string,Proc*> &FT) const
    {
	  FT[name_] = P_;
    }

private:
    string name_;
    Proc* P_;
};


class IfStmt: public Stmt
{
public:
    IfStmt(Expr *E,StmtList *S1, StmtList *S2)
    {
        E_ = E;
        S1_ = S1;
        S2_ = S2;
    }

    ~IfStmt() { delete E_; delete S1_; delete S2_; }

    void eval(map<string,int> &NT, map<string,Proc*> &FT) const
    {
	if (E_->eval(NT,FT) > 0)
		S1_->eval(NT,FT);
	else
		S2_->eval(NT,FT);
    }

private:
    Expr* E_;
    StmtList *S1_;
    StmtList *S2_;
};


class WhileStmt: public Stmt
{
public:
    WhileStmt(Expr *E,StmtList *S)
    {
        E_ = E;
        S_ = S;
    }

    ~WhileStmt() { delete E_; delete S_; }

    void eval(map<string,int> &NT, map<string,Proc*> &FT) const
    {
	while (E_->eval(NT,FT) > 0)
		S_->eval(NT,FT);
    }

private:
    Expr* E_;
    StmtList *S_;
};

#endif