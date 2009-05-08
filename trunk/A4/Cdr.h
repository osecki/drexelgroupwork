/**
 *  Program:  Cdr.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef CDR_H
#define CDR_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Cdr : public Expr
{
public:
    Cdr (Expr* op1 = NULL);
    virtual ~Cdr() {delete op1_;};
    virtual Element* eval(map<string,Element*> NT) const;
private:
    Expr* op1_;
};

#endif
