#ifndef PLUS_H
#define PLUS_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;
class Element;

class Plus : public Expr
{
public:
    Plus(Expr* op1 = NULL, Expr* op2 = NULL);
    virtual ~Plus() {delete op1_; delete op2_;};
		// Changed environment table here
		virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
