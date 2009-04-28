/**
 * Program:  Concat.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/

#ifndef CONCAT_H
#define CONCAT_H

#include <map>
#include <string>
#include "Expr.h"
#include "ConsCell.h"
#include<vector>


using namespace std;

class Proc;

class Concat : public Expr
{
public:
    Concat (Expr* op1 = NULL, Expr* ops2 = NULL);
    virtual ~Concat() {delete op1_; delete op2_;};
    virtual Element* eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
