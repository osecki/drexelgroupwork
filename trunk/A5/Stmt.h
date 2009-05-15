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
    // Changed environment table here
		virtual void eval(map<string,Element*> &NT) const = 0;

private:
};

#endif
