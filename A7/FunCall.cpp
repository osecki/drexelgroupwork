#include <map>
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
	// Load up parameters, previous FP, return address
	
	// Call apply
	
	// (hard) Jump to start of program 
	ralProgram.push_back("JMP L_" + name_);
	return "";
}
