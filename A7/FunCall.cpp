#include <map>
#include "Proc.h"
#include "FunCall.h"

FunCall::FunCall(string name, list<Expr*> *AL)
{
    name_= name;
    AL_ = AL;
}

FunCall::~FunCall() { delete AL_; }

/*Element* FunCall::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return FT[name_]->apply(NT, FT, AL_);
}*/

string FunCall::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &ralProgramFT) const
{
	// TODO
	return "";
}
