#ifndef TIMES_H
#define TIMES_H

#include <map>
#include <string>
#include "Expr.h"
#include "ConsCell.h"
#include<vector>

using namespace std;

class Proc;

class Times : public Expr
{
public:
    Times(Expr * op1 = NULL, Expr * op2 = NULL);
    virtual ~Times() {delete op1_; delete op2_;};
		// Changed environment table here
		virtual Element* eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
