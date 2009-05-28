#ifndef STMT_H
#define STMT_H

#include <map>
#include <vector>
#include <string>
#include "Expr.h"
using namespace std;

class StmtList;

class Stmt
{
public:
    Stmt() {};
    virtual ~Stmt() {};
    virtual void translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const = 0;
private:
};

#endif
