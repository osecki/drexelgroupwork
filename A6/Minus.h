#ifndef MINUS_H
#define MINUS_H

#include <map>
#include <string>
#include <vector>
#include "Expr.h"
using namespace std;

class Minus : public Expr
{
public:
    Minus(Expr* op1 = NULL, Expr* op2 = NULL);
    virtual ~Minus() {delete op1_; delete op2_;};
    virtual string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
