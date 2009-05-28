#ifndef NUMBER_H
#define NUMBER_H

#include <map>
#include <vector>
#include <string>
#include "Expr.h"

class Number : public Expr
{
public:
    Number(int value = 0);
    string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const;
private:
    int value_;
};

#endif
