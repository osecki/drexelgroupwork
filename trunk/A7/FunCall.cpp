#include <map>
#include <iostream>
#include "Proc.h"
#include "Program.h"
#include <sstream>
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
	FT[name_]->apply(constantValues, symbolTable, ralProgram, FT, *AL_, name_);

    string newTemp;
    stringstream out;
    out << Program::temporaryVarCounter;
    newTemp = "T" + out.str();
    Program::temporaryVarCounter++;

    SymbolDetails newSymbolTemp(-1, "Temporary", -1);
    symbolTable[newTemp] = newSymbolTemp;
    ralProgram.push_back("STO " + newTemp);

    return newTemp;
}
