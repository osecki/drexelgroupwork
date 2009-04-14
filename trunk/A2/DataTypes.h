/*
 * file:  program.h (contains declarations of Program, StmtList, Stmt, Expr)
 * Author: Jeremy Johnson 
 * Date: 2/05/07
 *
 * Description:
 */
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;


// forward declarations 
// StmtList used by IfStmt and WhileStmt which are Stmt
// Proc which contains StmtList used in Expr, Stmt, StmtList 
class StmtList;
class Proc;

class Expr
{
public:
	Expr() {};
	virtual ~Expr() {};  
	virtual int eval(map<string,int> NT, map<string,Proc*> FT) const = 0;  

private:
};

class Number : public Expr
{
public:
	Number(int value = 0);
	virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
private:
	int value_;
};


class Ident : public Expr
{
public:
	Ident(string name = "");
	virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
private:
	string name_;
};

class Times : public Expr
{
public:
	Times(Expr * op1 = NULL, Expr * op2 = NULL);
	virtual ~Times() {delete op1_; delete op2_;};
	virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
private:
	Expr* op1_;
	Expr* op2_;
};

class Plus : public Expr
{
public:
	Plus(Expr* op1 = NULL, Expr* op2 = NULL);
	virtual ~Plus() {delete op1_; delete op2_;};
	virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
private:
	Expr* op1_;
	Expr* op2_;
};

class Minus : public Expr
{
public:
	Minus(Expr* op1 = NULL, Expr* op2 = NULL);
	virtual ~Minus() {delete op1_; delete op2_;};
	virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
private:
	Expr* op1_;
	Expr* op2_;
};

class FunCall : public Expr
{
public:
	FunCall(string name, list<Expr*> *AL);
	virtual ~FunCall();
	virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
private:
	string name_;
	list<Expr*> *AL_;
};


class Stmt 
{
public:
	Stmt() {};
	virtual ~Stmt() {};  
	virtual void eval(map<string,int> &NT, map<string,Proc*> &FT) const = 0;  

private:
};


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


class StmtList 
{
public:
	StmtList() {};
	void eval(map<string,int> &NT, map<string,Proc*> &FT);  
	void insert(Stmt *T);  

private:
	list<Stmt*> SL_;
};

class Proc
{
public:
	Proc(list<string> *PL, StmtList *SL);
	~Proc() {delete SL_; };  
	int apply(map<string,int> &NT, map<string,Proc*> &FT, list<Expr*> *EL);
private:
	StmtList *SL_;
	list<string> *PL_;
	int NumParam_;
};

class Program 
{
public:
	Program(StmtList *SL);
	~Program() {delete SL_; };  
	void dump();
	void eval();  

private:
	StmtList *SL_;
	map<string,int> NameTable_;
	map<string,Proc*> FunctionTable_;
};
