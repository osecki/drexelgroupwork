/**
 * Program:  Car.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef CAR_H
#define CAR_H

#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class Car : public Expr
{
public:
    Car (Expr* op1 = NULL);
    virtual ~Car() {delete op1_;};
    virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT) const;
private:
    Expr* op1_;
};

#endif
