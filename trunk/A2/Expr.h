#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>
using namespace std;

class Proc;

class Expr
{
public:
    virtual ~Expr() {};
    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const = 0;
private:
};

#endif
