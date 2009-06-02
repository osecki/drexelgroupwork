#include <map>
#include "AssignStmt.h"
#include <vector>
#include "Program.h"
#include <iostream>
using namespace std;

AssignStmt::AssignStmt(string name, Expr *E)
{
	name_ = name;
	E_ = E;
}

/*void AssignStmt::eval(map<string,int> &T) const
{
	T[name_] = E_->eval(T);
}*/

void AssignStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT) const
{
	ralProgram.push_back("; +assign (" + name_ + ")");
	//  Look into constant table for Ident. If it is there get value from it, otherwise create new Ident and add to symbol table
	map<string, SymbolDetails>::iterator location = symbolTable.find(name_);
	if ( location == symbolTable.end() )
	{
		// Create new and add to the symbol table
		SymbolDetails tempDetails (-1, "Variable", -1);
		symbolTable[name_] = tempDetails;
	}

	// Perform the necessary RAL instructions
	//string offset = E_->translate(constantValues, symbolTable, ralProgram, FT);

    // Perform the necessary RAL instructions
    // TODO dynamic cast instead of looking at return value
    string returnAddress = E_->translate(constantValues, symbolTable, ralProgram, FT);
    if(returnAddress != "") {
        ralProgram.push_back("LDO " + E_->translate(constantValues, symbolTable, ralProgram, FT));
    }
	ralProgram.push_back("STO " + name_);


	/*
	ralProgram.push_back("LD FP");
	ralProgram.push_back("ADD " + offset);
	ralProgram.push_back("ST FPB");
	ralProgram.push_back("LDI FPB");
	// assignments have relative memory locations
	ralProgram.push_back("STI " + name_);
	*/



	ralProgram.push_back("; -assign (" + name_ + ")");
}

