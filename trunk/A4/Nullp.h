/**
 *  Program:  Nullp.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef NULLP_H
#define NULLP_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Nullp : public Expr
{
public:
    Nullp (Expr* op1 = NULL);
    virtual ~Nullp() {delete op1_;};
    virtual Element* eval(map<string,Element*> &NT) const;
private:
    Expr* op1_;
};

#endif
