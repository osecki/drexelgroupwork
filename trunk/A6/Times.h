#ifndef TIMES_H
#define TIMES_H

#include <map>
#include <string>
#include "Expr.h"
using namespace std;

class Times : public Expr
{
public:
    Times(Expr * op1 = NULL, Expr * op2 = NULL);
    virtual ~Times() {delete op1_; delete op2_;};
    virtual string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
