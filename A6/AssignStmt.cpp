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

void AssignStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const{

		//  Look into the constant table for the Ident. If it is there
		//  get the value from it otherwise create the new Ident and add to symbol table

		map<string, SymbolDetails>::iterator location = symbolTable.find(name_);

		if ( location!=symbolTable.end() ) {
			// already there nothing to do
			//cout<<"found in the symbol table"<<endl;
		} else
		{
			// create new and add to the symbol table
			SymbolDetails newSymbolVar(-1,"Variable",-1);

			//cout<<"Not in the symbol table creating new variable "<<name_<<endl;
			symbolTable[name_] = newSymbolVar;
		}

		// load the temporary variable found from the translating the expression

		string temp = E_->translate(constantValues, symbolTable);

		cout<<"LD	"<<temp<<endl;

		// now store it into the variable
		cout<<"ST	"<<name_<<endl;

}