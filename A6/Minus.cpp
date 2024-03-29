#include "Minus.h"
#include "Expr.h"
#include "Number.h"
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include "Program.h"
using namespace std;

Minus::Minus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

string Minus::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const
{
	  // Handle two operands and the Load and operator
	  string temp1, temp2;
	  if ( OPTIMIZE)
	  {
			  temp1 = op2_->translate(constantValues, symbolTable, ralProgram);
			  temp2 = op1_->translate(constantValues, symbolTable, ralProgram);

				ralProgram.push_back("LDA " + temp2);
				ralProgram.push_back("SUB " + temp1);
		}
    else
	  {
		    temp1 = op1_->translate(constantValues, symbolTable, ralProgram);
			  temp2 = op2_->translate(constantValues, symbolTable, ralProgram);

				ralProgram.push_back("LDA " + temp1);
				ralProgram.push_back("SUB " + temp2);
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

