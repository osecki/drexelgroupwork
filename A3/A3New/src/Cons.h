/**
 *  Program:  Cons.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#ifndef CONS_H
#define CONS_H

#include <map>
#include <string>
#include "Expr.h"
#include "ConsCell.h"
#include<vector>


using namespace std;

class Proc;


class Cons : public Expr
{
public:
    Cons (Expr* op1 = NULL, Expr* op2 = NULL);
    virtual ~Cons() {delete op1_; delete op2_; };
    Element* eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const;
private:
    Expr* op1_;
	Expr* op2_;
};

#endif
