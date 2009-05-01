#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>
#include "Memory.h"
using namespace std;

class Proc;
class Element;

class Expr
{
public:
    virtual ~Expr() {};
		// Changed environment table here
		virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const = 0;
private:
};

#endif
