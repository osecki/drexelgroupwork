#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "Program.h"
#include "Proc.h"
#include "FunCall.h"
#include "DefineStmt.h"
#include "Number.h"


int Program::constantCounter = 1;
int Program::temporaryVarCounter = 1;
int Program::labelCounter = 1;

Program::Program(StmtList *SL)
{
    constantValues.clear();
    symbolTable.clear();
    FT.clear();
    SL_ = SL;
}

void Program::dump() {
	dumpCode(cout);
}

void Program::dumpCode(ostream& out)
{
    for (unsigned int i=0; i< ralProgram.size(); i++)
        out << ralProgram[i] << endl;
}

void Program::translate()
{
    // Treat main as a function
    p = new Proc(new list<string>(), SL_);

    // Add the function to the function table
    d = new DefineStmt("main", p);
    d->translate(constantValues, symbolTable, ralProgram, FT);

	// cout << "There are " << constantValues.size() << " constants" << endl;
	
	// Constants + TEMP + SP + thisConstant
	int globalMemory = constantValues.size() + 4;
	ralProgram.push_back("LD " +Number::getConstant(constantValues, globalMemory));
	ralProgram.push_back("ST " + FP);
	//FunCall("main", new list<Expr*>()).translate();
	ralProgram.push_back("; CALL MAIN");
	//ralProgram.push_back("halt:");
	ralProgram.push_back("HLT");
	

	// Print out all the procs
	for(map<string, Proc*>::iterator iter = FT.begin(); iter != FT.end(); iter++) {
		Proc* p = iter->second;
		ralProgram.push_back("; +proc(" + iter->first +")");
		ralProgram.push_back(iter->first+":");
		vector<string> code = p->getCode();
		ralProgram.insert(ralProgram.end(), code.begin(), code.end());	
		ralProgram.push_back("; -proc(" + iter->first +")");
	}
	

    // Call it (with no parameters)
    
    
    
}

void Program::fixLabels()
{
    // Kill multiple labels in a row
    for ( unsigned int g = 0; g < ralProgram.size() - 1; g++ ) {
        // If two labels are found in a row
        if ( ralProgram[g].find(":") != string::npos && ralProgram[g+1].find(":") != string::npos ) {
            // Record labels
            string goodLabel = ralProgram[g].substr(0, ralProgram[g].find(":"));
            string LabelToDelete = ralProgram[g+1].substr(0, ralProgram[g+1].find(":"));

            // Loop through, change all instances of oneToDelete to good one
            for ( unsigned int h = 0; h < ralProgram.size(); h++) {
                if ( ralProgram[h].find(LabelToDelete) == 4 ){
                    ralProgram[h] = ralProgram[h].substr(0, 4) + goodLabel;
                }
            }

            // Delete second one
            vector<string>::iterator temp = ralProgram.begin() + g;
            ralProgram.erase(temp + 1, temp + 2);

            // Don't iterate count
            g = g - 1;
        }
    }

    // Make sure no labels are on a line of their own
    for ( unsigned  int i = 0; i < ralProgram.size(); i++ ) {
        if ( ralProgram[i].find(":") == ralProgram[i].length() - 1) {
            // Combine elements
            ralProgram[i] = ralProgram[i] + ralProgram[i+1];

            // Delete second one
            vector<string>::iterator temp = ralProgram.begin() + i;
            ralProgram.erase(temp + 1, temp + 2);
        }
    }
}

void Program::optimize()
{
    // Iterate through, looking for Store followed by Load with same variable.
    // If this is found, Delete the load
    for ( unsigned int i = 0; i < ralProgram.size() - 1; i++ ) {
        if ( ralProgram[i].find("STA") == 0 && ralProgram[i+1].find("LDA") == 0 &&
            (ralProgram[i].substr(3)).compare(ralProgram[i+1].substr(3)) == 0 ){
            // Delete the Load
            vector<string>::iterator temp = ralProgram.begin() + i;
            ralProgram.erase(temp + 1, temp + 2);
        }
    }
}

void Program::compile()
{
	// Primary Translate
    translate();
    
    // Save current state
    ofstream out("preLinking-program.txt");
    dumpCode(out);
    out.close();

    if (OPTIMIZE) {
        optimize();
    }

    fixLabels();

    link();
}


void Program::link()
{
	
    // Loop through the symbol table three times, giving each addresses
    int counter = 1;

    // Assign Constants an address
	constAddresses.clear(); 
    constAddresses[FP] = counter++;
    constAddresses[TEMP] = counter++;
    constAddresses[FPB] = counter++;
    

    for (map<int, string>::iterator a = constantValues.begin(); a != constantValues.end(); a++) {
    	//cout << "Constant: " << a->second << endl;
    	constAddresses[a->second] = counter;
        counter++;
    }
    
    // Calculate the addresses for labels
    map<string, int> labelValues;
    for ( unsigned  int i = 0; i < ralProgram.size(); i++ )
    {
    	if ( ralProgram[i].find(";") != 0 ) {
	        if ( ralProgram[i].find(":") != string::npos ) {
	            // First enter into map
	            labelValues[ralProgram[i].substr(0,ralProgram[i].find(":"))] = i + 1;
	
	            // Next delete from that one
	            ralProgram[i] = ralProgram[i].substr(ralProgram[i].find(":") + 1);
	        }
    	}
    }

    // Time to actually do the linking in the program
    for ( unsigned int j = 0; j < ralProgram.size(); j++ )
    {
    	if ( ralProgram[j].find(";") != 0 ) {
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
	            	if(constAddresses.find(tempVar) == constAddresses.end()) {
	            		cout << "Error, unknown variable: " << tempVar << endl;
	            		exit(1);
	            	}
	                int t2 = constAddresses[tempVar];
	                string s2;
	                stringstream out2;
	                out2 << t2;
	                s2 = out2.str();
	                ralProgram[j] = ralProgram[j].substr(0, ralProgram[j].find(" ") + 1) + s2;
	            }
	        }
    	}
    }
}