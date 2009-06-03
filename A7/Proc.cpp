#include <list>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
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
    vars = -1;
    temps = -1;
}

int Proc::getARSize() const {
	if(vars < 0 || temps < 0) {
		cout << "Program error, AR size accessed before translate!" << endl;
		exit(1);
	}

	return NumParam_ + vars + temps + 3;
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


int searchList(list<string> l, const string key) {
	int spot = -1;
	list<string>::iterator i;
	for(i= l.begin(); i != l.end(); i++) {
		spot++;
		if(*i == key) {
			return spot;
		}
	}
	return -1;
}


string Proc::getOffset(const string & name, map<int, string> & constants) {
	SymbolDetails s = symbolTable[name];
	int value;
	string type = s.getType();

	int spot = searchList(*PL_, name);
	if(spot >= 0) {
		value = spot;
	} else if(name.compare(PREV_FP) == 0) {
		value = NumParam_ + vars + temps + 1;
	} else if(name.compare(RETURN_ADDRESS) == 0) {
		value = NumParam_ + vars + temps + 2;
	} else if(name.compare(RETURN) == 0) {
		value = NumParam_ + vars + temps + 0;
	} else if ( type.compare("Temporary") == 0 ) {
  		value = NumParam_ + vars + s.getAddress();
    } else if (type.compare("Variable") == 0) {
    	value = NumParam_ + s.getAddress();
	} else {
		// TODO is this right?
		return name;
	}

	return Number::getConstant(constants, value);

	stringstream out;
	out << value;
	return out.str();
}


void Proc::apply(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT, const list<Expr*> parameters, string myName) {

	// Set parameters
	ralProgram.push_back("; set parameters");
	list<string>::iterator valueIterator = PL_->begin();
	for(list<Expr*>::const_iterator iter = parameters.begin(); iter != parameters.end(); iter++) {
		// Evaluate parameter
		Expr* e = *iter;
		string address = e->translate(constantValues, symbolTable, ralProgram, FT);
        // Save the value returned
        ralProgram.push_back("STA " + TEMP);
        ralProgram.push_back("LDA " + getOffset(*valueIterator, constantValues));
        ralProgram.push_back("ADD " + NEXT_FP);
        ralProgram.push_back("STA " + FPB);
        ralProgram.push_back("LDA " + TEMP);
        ralProgram.push_back("STI " + FPB);
		valueIterator++;
	}

    // Set PREV_FP
	ralProgram.push_back("; save previous FP");
	ralProgram.push_back("LDA [" + myName + "]");
	ralProgram.push_back("SUB " + Number::getConstant(constantValues, 2));
	ralProgram.push_back("ADD " + NEXT_FP);
	ralProgram.push_back("STA " + FPB);
	ralProgram.push_back("LDA " + FP);
	ralProgram.push_back("STI " + FPB);

	// Set FP
	ralProgram.push_back("; set FP");
	ralProgram.push_back("LDA " + NEXT_FP);
	ralProgram.push_back("STA " + FP);

	// Update NEXT_FP based on size of Activation Record
	ralProgram.push_back("; set " + NEXT_FP);
	ralProgram.push_back("LDA " + FP);
	ralProgram.push_back("ADD [" + myName + "]");
	ralProgram.push_back("STA " + NEXT_FP);

	// Set RETURN_ADDRESS
	ralProgram.push_back("; save return address");
	ralProgram.push_back("LDA [" + myName + "]");
	ralProgram.push_back("SUB " + Number::getConstant(constantValues, 1));
	ralProgram.push_back("ADD " + FP);
	ralProgram.push_back("STA " + FPB);
	ralProgram.push_back("LDA " + LINE);
	ralProgram.push_back("STI " + FPB);

	// (hard) Jump to start of progra
	ralProgram.push_back("JMP L_" + myName);
    ralProgram.push_back("; previous funcall should jump here");
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
            if(c->first != RETURN) {
                (*c).second.setAddress(vars);
                vars++;
            }
		} else {
			constants++;
		}
    }

    ralProgram.push_back("; Back-up stack pointer");
    ralProgram.push_back("LDA " + FP);
    ralProgram.push_back("STA " + TEMP);

    ralProgram.push_back("; Reset stack pointer");
    ralProgram.push_back("LDO " + getOffset(PREV_FP, constantValues));
    ralProgram.push_back("STA " + FP);

    ralProgram.push_back("; Jump back ");
    ralProgram.push_back("LDA " + TEMP);
    ralProgram.push_back("ADD " + getOffset(RETURN_ADDRESS, constantValues));
    ralProgram.push_back("STA " + FPB);
    ralProgram.push_back("LDI " + FPB);
    ralProgram.push_back("STA " + FPB);

    // Save return value
    ralProgram.push_back("; before jumping get return value");
    //ralProgram.push_back("LDO " + RETURN);
    ralProgram.push_back("LDA " + TEMP); // Temp is current FP
    ralProgram.push_back("ADD " + getOffset(RETURN, constantValues));
    ralProgram.push_back("STA " + TEMP); // Mangle Temp with return address
    ralProgram.push_back("LDI " + TEMP); // Load the return value to accumulator

    ralProgram.push_back("JMI " + FPB);

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
			itr = ralProgram.insert(itr, "LDA " + FP);
			itr++;
			itr = ralProgram.insert(itr, "ADD " + getOffset(address, constantValues));
			itr++;
			itr = ralProgram.insert(itr, "STA " + FPB);
			itr++;
			itr = ralProgram.insert(itr, "LDI " + FPB);

		} else if (instruction == "STO") {
			// Remove fake instruction
			ralProgram.erase(itr);
			itr = ralProgram.insert(itr, "; " + fullInstruction);
			itr++;
			itr = ralProgram.insert(itr, "STA " + TEMP);
			itr++;
			itr = ralProgram.insert(itr, "LDA " + FP);
			itr++;
			itr = ralProgram.insert(itr, "ADD " + getOffset(address, constantValues));
			itr++;
			itr = ralProgram.insert(itr, "STA " + FPB);
			itr++;
			itr = ralProgram.insert(itr, "LDA " + TEMP);
			itr++;
			itr = ralProgram.insert(itr, "STI " + FPB);
		} else {
			 itr++;
		}
    }
}
