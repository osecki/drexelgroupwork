#include "Ident.h"
#include <map>
#include "Program.h"
#include <sstream>
#include <iostream>
using namespace std;

Ident::Ident(string name)
{
    name_ = name;
}

/*int Ident::eval(map<string,int> T) const
{	
	return T[name_];
}*/

string Ident::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const{
	// look into the constant table for the Ident. If it is there
	// get the value from it otherwise create the new Ident and add to the symbol table
	map<string, SymbolDetails>::iterator location = symbolTable.find(name_);
	if (symbolTable.end() != location ) {
		// already there nothing to do
	} else {
		// create new and add to the symbol table
		SymbolDetails newSymbolVar(-1,"Variable",-1);
		symbolTable[name_] = newSymbolVar;
	}

	cout<<"LD	"<<name_<<endl;

	// create new temporary variable then Store the new ident there
	string newTemp;
	stringstream out;
	Program p;
	out << p.temporaryVarCounter;
	newTemp = "T" + out.str();

	p.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1,"Temporary",-1);

	symbolTable[newTemp] = newSymbolTemp;

	cout<<"ST	"<<newTemp<<endl;

	return newTemp;
}

