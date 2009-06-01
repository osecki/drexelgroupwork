#include "Proc.h"
#include <list>
#include <map>
#include <string>
#include "StmtList.h"
#include <iostream>

Proc::Proc(list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    NumParam_ = PL->size();
}

// TODO This function changed eval() to translate(), but more needs to be
// done
int Proc::apply(map<string,int> &NT, map<string,Proc*> &FT, list<Expr*> *EL)
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
		// NNT[*p] = (*e)->translate(NT,FT); TODO

	// evaluate function body using new name table and old function table

	//SL_->translate(NNT,FT); TODO
	if ( NNT.find("return") != NNT.end() )
		return NNT["return"];
	else {
		cout << "Error:  no return value" << endl;
		exit(1);
	}
    // Unreachable
    return -1;
}

string Proc::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram)
{
    SL_->translate(constantValues, symbolTable, ralProgram);

	return "";
}
