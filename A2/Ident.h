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
    virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT) const;
private:
    string name_;
};

#endif
