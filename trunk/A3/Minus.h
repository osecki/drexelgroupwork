#ifndef MINUS_H
#define MINUS_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Minus : public Expr
{
public:
    Minus(Expr* op1 = NULL, Expr* op2 = NULL);
    virtual ~Minus() {delete op1_; delete op2_;};
		// Changed environment table here
		virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
