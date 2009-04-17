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
    AssignStmt(string name="", Expr *E=NULL);
    ~AssignStmt() {delete E_;};
    void eval(map<string,int> &NT, map<string,Proc*> &FT) const;
private:
    string name_;
    Expr* E_;
};

class DefineStmt : public Stmt
{
public:
    DefineStmt(string name="", Proc *P=NULL);
    virtual ~DefineStmt();
    virtual void eval(map<string,int> &NT, map<string,Proc*> &FT) const;
private:
    string name_;
    Proc* P_;
};


class IfStmt: public Stmt
{
public:
    IfStmt(Expr *E,StmtList *S1, StmtList *S2);
    ~IfStmt();
    void eval(map<string,int> &NT, map<string,Proc*> &FT) const;
private:
    Expr* E_;
    StmtList *S1_;
    StmtList *S2_;
};

class WhileStmt: public Stmt
{
public:
    WhileStmt(Expr *E,StmtList *S);
        ~WhileStmt();
    void eval(map<string,int> &NT, map<string,Proc*> &FT) const;
private:
    Expr* E_;
    StmtList *S_;
};

#endif
