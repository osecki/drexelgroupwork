#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <vector>
#include <string>
#include "SymbolDetails.h"
using namespace std;

class Expr
{
public:
	Expr() {};
	virtual ~Expr() {};
	virtual string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const=0;
private:
};

#endif
