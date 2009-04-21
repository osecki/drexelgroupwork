#ifndef INTP_H
#define INTP_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Intp : public Expr
{
public:
    Intp (Expr* op1 = NULL);
    virtual ~Intp() {delete op1_;};
    virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT) const;
private:
    Expr* op1_;
};

#endif
