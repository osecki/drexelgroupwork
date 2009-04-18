#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>
#include "Proc.h"

using namespace std;

class Proc;

class Expr
{
public:
    Expr() {};
    virtual ~Expr() {};
    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const = 0;

private:
};

#endif
