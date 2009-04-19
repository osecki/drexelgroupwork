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
    virtual ~FunCall();
    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
private:
    string name_;
    list<Expr*> *AL_;
};

#endif
