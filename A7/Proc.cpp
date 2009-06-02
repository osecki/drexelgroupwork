#include <list>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include "StmtList.h"
#include "Proc.h"
#include "Program.h"
#include "Number.h"

#define RETURN_ADDRESS "RETURN_ADDRESS"
#define PREV_FP string("PREV_FP")
#define RETURN string("return")

Proc::Proc(list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    NumParam_ = PL->size();
    symbolTable.clear();
    ralProgram.clear();
}

// Output program to stream
void Proc::insert(ostream &out)  const {
	for(vector<string>::const_iterator iter = ralProgram.begin(); iter!=ralProgram.end(); iter++) {
		out << *iter << endl;
	}	
}

// Output operator
ostream& operator<<(ostream & out, const Proc &p) {
	p.insert(out);
	return out;
}

vector<string> Proc::getCode() {
	return ralProgram;
}


string Proc::getOffset(const string & name, map<int, string> & constants) {
	SymbolDetails s = symbolTable[name];
	int value;
	string type = s.getType();
	if(name.compare(PREV_FP) == 0) {
		value = NumParam_ + vars + temps + 1;
	} else if(name.compare(RETURN_ADDRESS) == 0) {
		value = NumParam_ + vars + temps + 2; 
	} else if(name.compare(RETURN) == 0) {
		value = NumParam_ + vars + temps;
	} else if ( type.compare("Temporary") == 0 ) {
  		value = NumParam_ + vars + s.getAddress();
    } else if (type.compare("Variable") == 0) {
    	value = NumParam_ + s.getAddress();
	} else {
		return name;
	}
	
	return Number::getConstant(constants, value);
	
	stringstream out;
	out << value;
	return out.str();
}



// Convert statement list into RAL code
void Proc::translate(map<int, string> &constantValues, map<string, Proc*> &FT)
{
	// Translate all the statements
    SL_->translate(constantValues, symbolTable, ralProgram, FT);

    temps = 0;
    vars = 0;
    constants = 0;
    
    // Count variables
    for (map<string, SymbolDetails>::iterator c = symbolTable.begin(); c != symbolTable.end(); c++) {
    	string type = (*c).second.getType();
		if ( type.compare("Temporary") == 0 ) {
			(*c).second.setAddress(temps);
	  		temps++;
        } else if (type.compare("Variable") == 0) {
        	(*c).second.setAddress(vars);
        	vars++;
		} else {
			constants++;
		}
    }    
    
    ralProgram.push_back("; Reset stack pointer"); 
    ralProgram.push_back("LDO " + getOffset(PREV_FP, constantValues));
    ralProgram.push_back("ST " + FP);
    ralProgram.push_back("; Jump back ");
    ralProgram.push_back("LD " + FP);
    ralProgram.push_back("ADD " + getOffset(RETURN_ADDRESS, constantValues)); 
    ralProgram.push_back("ST " + FPB);
    ralProgram.push_back("JPI " + FPB);
 
    // Fix up all the LDO and STO calls
    for(vector<string>::iterator itr = ralProgram.begin(); itr != ralProgram.end();) {
    	string fullInstruction = *itr;
		stringstream in(fullInstruction);
		string instruction, address;
		in >> instruction >> address;
		
		if(instruction == "LDO") {
			// Remove fake instruction
			ralProgram.erase(itr);
			// Add indirect
			itr = ralProgram.insert(itr, "; " + fullInstruction);
			itr++; 
			itr = ralProgram.insert(itr, "LD " + FP);
			itr++;
			itr = ralProgram.insert(itr, "ADD " + getOffset(address, constantValues));
			itr++;
			itr = ralProgram.insert(itr, "ST " + FPB);
			itr++;
			itr = ralProgram.insert(itr, "LDI " + FPB);
			
		} else if (instruction == "STO") {
			// Remove fake instruction
			ralProgram.erase(itr);
			itr = ralProgram.insert(itr, "; " + fullInstruction);
			itr++; 
			itr = ralProgram.insert(itr, "ST " + TEMP);
			itr++;
			itr = ralProgram.insert(itr, "LD " + FP);
			itr++;
			itr = ralProgram.insert(itr, "ADD " + getOffset(address, constantValues));
			itr++;
			itr = ralProgram.insert(itr, "ST " + FPB);
			itr++;
			itr = ralProgram.insert(itr, "LD " + TEMP);
			itr++;
			itr = ralProgram.insert(itr, "STI " + FPB);
		} else {
			 itr++;
		}
		
		// TODO - Handle JDO?
    }
}
