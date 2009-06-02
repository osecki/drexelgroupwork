#include <map>
#include <iostream>
#include "Proc.h"
#include "FunCall.h"

FunCall::FunCall(string name, list<Expr*> *AL)
{
    name_= name;
    AL_ = AL;
}

FunCall::~FunCall() { 
	delete AL_; 
}


string FunCall::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT) const
{
	// Look up function in table
	if(FT.find(name_) == FT.end()) {
		cout << "No such function '" << name_ << "'" << endl;
		exit(1);
	}
	

	// Call apply
	FT[name_]->apply(constantValues, symbolTable, ralProgram, FT, *AL_);
	
	// (hard) Jump to start of program 
	// TODO this does not work
	ralProgram.push_back("JMP L_" + name_);
	return "";
}
