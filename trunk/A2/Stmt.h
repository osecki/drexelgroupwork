#ifndef STMT_H
#define STMT_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Stmt
{
public:
    Stmt() {};
    virtual ~Stmt() {};
    virtual void eval(map<string,int> &NT, map<string,Proc*> &FT) const = 0;

private:
};

#endif
