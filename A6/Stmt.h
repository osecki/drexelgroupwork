#ifndef STMT_H
#define STMT_H

#include <map>
#include <string>
#include "Expr.h"
using namespace std;

class Stmt
{
public:
    Stmt() {};
    virtual ~Stmt() {};
    virtual void eval(map<string,int> T) const;
private:
};

#endif
