#include <map>
#include "AssignStmt.h"
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

void AssignStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const
{
		//  Look into constant table for Ident. If it is there get value from it, otherwise create new Ident and add to symbol table
		map<string, SymbolDetails>::iterator location = symbolTable.find(name_);
		if ( location == symbolTable.end() )
		{
			// Create new and add to the symbol table
			SymbolDetails tempDetails (-1, "Variable", -1);
			symbolTable[name_] = tempDetails;
		}

		// Perform the necessary RAL instructions
		cout << "LD	" << E_->translate(constantValues, symbolTable) << endl;
		cout << "ST	" <<name_ << endl;
}

