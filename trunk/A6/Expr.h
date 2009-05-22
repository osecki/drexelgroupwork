#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>
using namespace std;

class Expr
{
public:
	Expr() {};
	virtual ~Expr() {};
	virtual int eval(map<string,int> T) const = 0;
private:
};

#endif
