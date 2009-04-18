#ifndef PROC_H
#define PROC_H

#include <map>
#include <string>
#include "StmtList.h"

using namespace std;

class Expr;

class Proc
{
public:
    Proc(list<string> *PL, StmtList *SL)
    {
	SL_ = SL;
	PL_ = PL;
	NumParam_ = PL->size();
    }

    ~Proc() {delete SL_; }

    int apply(map<string,int> &NT, map<string,Proc*> &FT, list<Expr*> *EL)
    {
	map<string,int> NNT;
	NNT.clear();

	// bind parameters in new name table

	list<string>::iterator p;
	list<Expr*>::iterator e;
	if (NumParam_ != EL->size()) {
		cout << "Param count does not match" << endl;
		exit(1);
	}
	for (p = PL_->begin(), e = EL->begin(); p != PL_->end(); p++, e++)
		NNT[*p] = (*e)->eval(NT,FT);

	// evaluate function body using new name table and old function table

	SL_->eval(NNT,FT);
	if ( NNT.find("return") != NNT.end() )
		return NNT["return"];
	else {
		cout << "Error:  no return value" << endl;
		exit(1);
	}
    }

private:
    StmtList *SL_;
    list<string> *PL_;
    int NumParam_;
};


#endif