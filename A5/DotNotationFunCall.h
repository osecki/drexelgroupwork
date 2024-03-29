/**
 *  Program:  DotNotationFunCall.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 5, Spring 2009
**/

#ifndef DOTNOTATIONFUNCALL_H
#define DOTNOTATIONFUNCALL_H

#include <list>
#include <map>
#include <string>
#include "Expr.h"
#include "FunCall.h"

using namespace std;

class Proc;

class DotNotationFunCall : public Expr
{
public:
    DotNotationFunCall(string name, FunCall* FC);
    virtual ~DotNotationFunCall();
    virtual Element* eval(map<string,Element*> &NT) const;
private:
    string name_;
    FunCall* FC_;
};

#endif
