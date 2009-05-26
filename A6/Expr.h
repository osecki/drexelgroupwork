#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>
#include "SymbolDetails.h"
using namespace std;

class Expr
{
public:
	Expr() {};
	virtual ~Expr() {};
	//virtual int eval(map<string,int> T) const = 0;
	virtual string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const=0;
private:
};

#endif
