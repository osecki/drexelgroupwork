#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>
using namespace std;

class Proc;
class Element;

class Expr
{
public:
    virtual ~Expr() {};
		// Changed environment table here
		virtual Element* eval(map<string,Element*> &NT) const = 0;
private:
};

#endif
