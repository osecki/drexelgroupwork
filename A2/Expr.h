#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>
#include "Element.h"
using namespace std;

class Proc;
class Element;

class Expr
{
public:
    virtual ~Expr() {};
    virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT) const = 0;
private:
};

#endif
