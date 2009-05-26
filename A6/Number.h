#ifndef NUMBER_H
#define NUMBER_H

#include <map>
#include <string>
#include "Expr.h"

class Number : public Expr
{
public:
    Number(int value = 0);
    //virtual int eval(map<string,int> T) const;
    string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const;
private:
    int value_;
};

#endif
