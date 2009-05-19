#ifndef FUNCALL_H
#define FUNCALL_H

#include <list>
#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class FunCall : public Expr
{
public:
    FunCall(string name, list<Expr*> *AL);
    FunCall(Expr* e, list<Expr*> *AL);
    string getName();
    virtual ~FunCall();
    virtual Element* eval(map<string,Element*> &NT) const;
private:
    string name_;
    Expr* expression;
    list<Expr*> *AL_;
};

#endif
