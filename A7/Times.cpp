#include "Times.h"
#include "Expr.h"
#include "Number.h"
#include <map>
#include <vector>
#include "Program.h"
#include <iostream>
#include <sstream>
using namespace std;

Times::Times(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

string Times::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const
{
	  // Handle two operands and load and operator
    string temp1, temp2;
	  if ( OPTIMIZE)
		{
			  string temp1 = op2_->translate(constantValues, symbolTable, ralProgram);
				string temp2 = op1_->translate(constantValues, symbolTable, ralProgram);
	  
				ralProgram.push_back("LDA " + temp2);
				ralProgram.push_back("MUL " + temp1);
		}
	  else
		{
			  string temp1 = op1_->translate(constantValues, symbolTable, ralProgram);
				string temp2 = op2_->translate(constantValues, symbolTable, ralProgram);
		
			 ralProgram.push_back("LDA " + temp1);
			 ralProgram.push_back("MUL " + temp2);
		} 	

		// Handle Final Store and Temporary Variable Creation
		Program P;
		string newTemp;
		stringstream out;
		out << P.temporaryVarCounter;
		newTemp = "T" + out.str();
		P.temporaryVarCounter++;

		SymbolDetails newSymbolTemp(-1, "Temporary", -1);
		symbolTable[newTemp] = newSymbolTemp;
		ralProgram.push_back("STA " + newTemp);

		return newTemp;
}

