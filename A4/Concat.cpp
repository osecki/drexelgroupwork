/**
 *  Program:  Concat.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#include "Concat.h"
#include "Expr.h"
#include "List.h"
#include <map>

Concat::Concat(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

Element* Concat::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const
{
    // Calls the concatenate() function from List
    List* l1 = (List*) (op1_->eval(NT,FT,memory));
    List* l2 = (List*) (op2_->eval(NT,FT,memory));

    int current = l1->getAddress();
    while(memory[current].cdr != NULL_POINTER) {
        current = memory[current].cdr;
    }

    memory[current].cdr = l2->getAddress();

    return l1;
}

