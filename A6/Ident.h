#ifndef IDENT_H
#define IDENT_H

#include <map>
#include <vector>
#include <string>
#include "Expr.h"
using namespace std;

class Ident : public Expr
{
public:
    Ident(string name = "");
    virtual string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const;
private:
    string name_;
};

#endif
