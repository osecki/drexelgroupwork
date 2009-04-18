#ifndef MATH_H
#define MATH_H



#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;


class Times : public Expr
{
public:
    Times(Expr * op1 = NULL, Expr * op2 = NULL)
    {
	op1_ = op1;
	op2_ = op2;
    }

    virtual ~Times() {delete op1_; delete op2_;}

    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const
    {
	return op1_->eval(NT,FT) * op2_->eval(NT,FT);
    }

private:
    Expr* op1_;
    Expr* op2_;
};


class Plus : public Expr
{
public:
    Plus(Expr* op1 = NULL, Expr* op2 = NULL)
    {
	op1_ = op1;
	op2_ = op2;
    }

    virtual ~Plus() {delete op1_; delete op2_;}

    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const
    {
	return op1_->eval(NT,FT) + op2_->eval(NT,FT);
    }

private:
    Expr* op1_;
    Expr* op2_;
};


class Minus : public Expr
{
public:
    Minus(Expr* op1 = NULL, Expr* op2 = NULL)
    {
	op1_ = op1;
	op2_ = op2;
    }

    virtual ~Minus() {delete op1_; delete op2_;}

    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const
    {
	return op1_->eval(NT,FT) - op2_->eval(NT,FT);
    }

private:
    Expr* op1_;
    Expr* op2_;
};

#endif

