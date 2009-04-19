#ifndef PLUS_H
#define PLUS_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

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

#endif
