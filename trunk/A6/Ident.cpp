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

string Ident::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const
{
	// Look into constant table for Ident. If there, get value from it, otherwise create new Ident and add to the symbol table
	map<string, SymbolDetails>::iterator location = symbolTable.find(name_);
	if (symbolTable.end() == location ) 
	{
		// Create new and add to the symbol table
		SymbolDetails newSymbolVar(-1, "Variable", -1);
		symbolTable[name_] = newSymbolVar;
	}

	cout<<"LD	"<<name_<<endl;

	// Create new temporary variable then Store the new ident there
	string newTemp;
	stringstream out;
	Program p;
	out << p.temporaryVarCounter;
	newTemp = "T" + out.str();
	p.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1, "Temporary", -1);
	symbolTable[newTemp] = newSymbolTemp;

	cout<<"ST	"<<newTemp<<endl;

	return newTemp;
}

