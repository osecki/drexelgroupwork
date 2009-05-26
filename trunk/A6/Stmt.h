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
    virtual void translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const = 0;
private:
};

#endif