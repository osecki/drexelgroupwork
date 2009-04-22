#ifndef CONCAT_H
#define CONCAT_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Concat : public Expr
{
public:
    Concat (Expr* op1 = NULL, Expr* ops2 = NULL);
    virtual ~Concat() {delete op1_; delete op2_;};
    virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
