/**
 *  Program:  Intp.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#ifndef INTP_H
#define INTP_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Intp : public Expr
{
public:
    Intp (Expr* op1 = NULL);
    virtual ~Intp() {delete op1_;};
    virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const;
private:
    Expr* op1_;
};

#endif
