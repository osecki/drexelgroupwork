#ifndef EXPR_H
#define EXPR_H

#include <map>
#include <string>

#include<vector>

using namespace std;

class Proc;
class Element;
class ConsCell;
class Expr
{
public:
    virtual ~Expr() {};
		// Changed environment table here
		virtual Element* eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const = 0;
private:
};

#endif
