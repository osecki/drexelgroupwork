/**
 *  Program:  Cons.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef CONS_H
#define CONS_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Cons : public Expr
{
public:
    Cons (Expr* op1 = NULL, Expr* op2 = NULL);
    virtual ~Cons() {delete op1_; delete op2_; };
    virtual Element* eval(map<string,Element*> NT) const;
private:
    Expr* op1_;
    Expr* op2_;
};

#endif
