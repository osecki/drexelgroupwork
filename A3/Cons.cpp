/**
 * Program:  Cons.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/

#include "Cons.h"
#include "Expr.h"
#include "List.h"
#include <map>
#include "ConsCell.h"
#include "Number.h"

#include<vector>


class Program;

Cons::Cons(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

Element* Cons::eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const
{
		// Calls the cons() function from List
    /*List* newL = new List((List*)op1_->eval(NT, FT));
    Element* two = (Element*)op2_->eval(NT, FT);
    newL->cons(two);
    return newL;*/
	// extract op1_(which is a list) index in the vector from the name table
	Element* left = op1_->eval(NT,FT,listMemory,avail);

// find the datas from the vector and create a list
//	Number index = new Number((List*)op1_->eval(NT, FT));
//	ConsCell firstCell = (ConsCell)listMemory[index.getValue()];
//
	// extract op2_ from the name table which should be a number or list
	Element* right = (Element*)op2_->eval(NT, FT,listMemory,avail);

    //if(right->thisAddress == -1)
        // allocate new memory

    Element* e = new Element;
    e->thisAddress = address of new ConsCell cc;
    e->isValue = false;
    e->value = left->cc.address;
    return e;

    // Now we have to set listMemory[left->thisAddress]->cdr to right->thisAddress
    // unless cdr is set, then we follow it

    // once we find end of car (because it could be a list)
    // we set it's cdr to 'right->thisAddress'


    // we then return left
    return left;





	newL->cons(two);

	// find available cells and push the elements into cells
	// avail == Program.SIZEOFMEMORY means the we are running out of memory

    cout << "here" << endl;

	if (avail < 8) {

		cout<<"avail "<<avail<<endl;
		// the list is empty then only add the add the car part
		cout<<newL->nullp()<<endl;
		if (newL->nullp() == 0) {

			// if the car is only a number
			//if (two)
			cout<<"inside first block"<<endl;
			ConsCell newConsCell;
			Element* number = new Number(-1);
			number->intOrPtr = false;

			two->intOrPtr = true;

			newConsCell.carPtr = two;
			newConsCell.cdrPtr = number;

			listMemory[avail] = newConsCell;

			Number* carVal = (Number*)newConsCell.getCarPtr();
			Number* cdrVal = (Number*)newConsCell.getCdrPtr();


			cout<<"ConsCell["<<0<<"] "<<carVal->getValue()<<", "<<cdrVal->getValue()<<endl;
			// implement if the car is another list ????????

		} else {
			ConsCell newConsCell;
			int number = newL->getStartAddress();
			Number* startAddress = new Number(number);
			newConsCell.carPtr = two;
			newConsCell.cdrPtr = (Element*)startAddress;
			listMemory[avail] = newConsCell;

		}

	} else {
		// call the garbage collector to mark and sweep

	}
	//VirtualMemory.setStartIndexOfList();
	newL->setStartAddress(avail);
	// increase the next available pointer in the memory to point to next available spot
	avail++;
	return newL;
}
