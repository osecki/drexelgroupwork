/**
 *  Program:  Element.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef ELEMENT_H
#define ELEMENT_H

#include "Expr.h"
#include<iostream>
using namespace std;

class Proc;
class Number;

class Element : public Expr {
public:
  // These two functions are here because input can be list or number
    virtual int listp();
    virtual int intp();
    virtual Element* eval(map<string,Element*> &NT) const = 0;
    virtual string toString(map<string,Element*> NT) const = 0;
};


#endif

