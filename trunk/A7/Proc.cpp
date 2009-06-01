#include <list>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include "StmtList.h"
#include "Proc.h"
#include "Number.h"

#define RETURN_ADDRESS "RETURN_ADDRESS"
#define PREV_FP "PREV_FP"
#define RETURN "return"

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
		return value;
	}
	
	return Number::getConstant(constants, value);
	
	stringstream out;
	out << value;
	return out.str();
}



// Convert statement list into RAL code
void Proc::translate(map<int, string> &constantValues, map<string, Proc*> &FT)
{
    SL_->translate(constantValues, symbolTable, ralProgram, FT);
    ralProgram.push_back("; Reset stack pointer"); 
    ralProgram.push_back("LDO " + getOffset(PREV_FP, constantValues));
    ralProgram.push_back("ST FP");
    ralProgram.push_back("; Jump back ");
    ralProgram.push_back("JPI " + getOffset(RETURN_ADDRESS, constantValues));
    

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
			itr = ralProgram.insert(itr, "LD FP");
			itr++;
			itr = ralProgram.insert(itr, "ADD " + getOffset(address, constantValues));
			itr++;
			itr = ralProgram.insert(itr, "ST FPB");
			itr++;
			itr = ralProgram.insert(itr, "LDI FPB");
			
		} else if (instruction == "STO") {
			// Remove fake instruction
			ralProgram.erase(itr);
			itr = ralProgram.insert(itr, "ST TEMP");
			itr++;
			itr = ralProgram.insert(itr, "LD FP");
			itr++;
			itr = ralProgram.insert(itr, "ADD " + getOffset(address, constantValues));
			itr++;
			itr = ralProgram.insert(itr, "ST FPB");
			itr++;
			itr = ralProgram.insert(itr, "LD TEMP");
			itr++;
			itr = ralProgram.insert(itr, "STI FPB");
		} else {
			 itr++;
		}
		
		// TODO - Handle JDO?
    }
}




/*
void Proc::link(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT)
{
    // Loop through the symbol table three times, giving each addresses
    int counter = 1;

    // Assign Constants an address
    for (map<string, SymbolDetails>::iterator a = symbolTable.begin(); a != symbolTable.end(); a++) {
        if ( ((*a).second.getType()).compare("Constant") == 0 ) {
            (*a).second.setAddress(counter);
            counter++;
        }
    }

    // Assign Variables an address
    for (map<string, SymbolDetails>::iterator b = symbolTable.begin(); b != symbolTable.end(); b++) {
        if ( ((*b).second.getType()).compare("Variable") == 0 ) {
            (*b).second.setAddress(counter);
            counter++;
        }
    }

    // Assign Temporaries an address
    for (map<string, SymbolDetails>::iterator c = symbolTable.begin(); c != symbolTable.end(); c++) {
        if ( ((*c).second.getType()).compare("Temporary") == 0 ) {
            (*c).second.setAddress(counter);
            counter++;
        }
    }

    // Calculate the addresses for labels
    map<string, int> labelValues;
    for ( unsigned  int i = 0; i < ralProgram.size(); i++ )
    {
        if ( ralProgram[i].find(":") != string::npos ) {
            // First enter into map
            labelValues[ralProgram[i].substr(0,ralProgram[i].find(":"))] = i + 1;

            // Next delete from that one
            ralProgram[i] = ralProgram[i].substr(ralProgram[i].find(":") + 1);
        }
    }

    // Time to actually do the linking in the program
    for ( unsigned int j = 0; j < ralProgram.size(); j++ )
    {
        string tempVar = ralProgram[j].substr(ralProgram[j].find(" ") + 1);

        if ( ralProgram[j].find("HLT") == string::npos) {
            // Need to decide if we look in symbolTable or labelTable
            if ( (tempVar.substr(0, 1)).compare("L") == 0 ) {
                int t1 = labelValues[tempVar];
                string s1;
                stringstream out1;
                out1 << t1;
                s1 = out1.str();
                ralProgram[j] = ralProgram[j].substr(0, ralProgram[j].find(" ") + 1) + s1;
            } else {
                int t2 = symbolTable[tempVar].getAddress();
                string s2;
                stringstream out2;
                out2 << t2;
                s2 = out2.str();
                ralProgram[j] = ralProgram[j].substr(0, ralProgram[j].find(" ") + 1) + s2;
            }
        }
    }
}
*/
