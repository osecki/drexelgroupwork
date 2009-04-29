#ifndef IDENT_H
#define IDENT_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Ident : public Expr
{
public:
    Ident(string name = "");
		// Changed environment table here
		virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const;
private:
    string name_;
};

#endif
