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
    FT.clear();
    SL_ = SL;
}

void Program::dump() {
	ofstream fout("program.txt");
	dumpCode(fout);
	fout.close();

	ofstream memout("mem.txt");
	dumpMemory(memout);

    cout << "Final program: program.txt has " << ralProgram.size() << " lines." << endl
         << "Initial memory: mem.txt has " << constAddresses.size() << " lines" << endl;
}

void Program::dumpMemory(ostream& out)
{
	// Sort map by values (big hack)

	vector<SymbolDetails> v;
	map<SymbolDetails, string> m;

	for(map<string,SymbolDetails>::iterator iter = constAddresses.begin(); iter!=constAddresses.end(); iter++) {
		v.push_back(iter->second);
		m[iter->second] = iter->first;
	}

	sort(v.begin(),v.end());

	for(vector<SymbolDetails>::iterator i = v.begin(); i!= v.end(); i++) {
		out << setw(10) << left << i->getAddress() << " " << i->getValue() << "; " << m[*i] << endl;
	}
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
    map<string, SymbolDetails> symbolTable;
		d->translate(constantValues, symbolTable, ralProgram, FT);

	FunCall("main", new list<Expr*>()).translate(constantValues, symbolTable, ralProgram, FT);
    ralProgram.pop_back();

	ralProgram.push_back("HLT");

	// Print out all the procs
	for(map<string, Proc*>::iterator iter = FT.begin(); iter != FT.end(); iter++) {
		Proc* p = iter->second;
		ralProgram.push_back("; +proc(" + iter->first +")");
		ralProgram.push_back("L_" + iter->first+":");
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

void Program::compile()
{
	// Primary Translate
    translate();

    // Save current state
    ofstream out1("preLabel-program.txt");
    dumpCode(out1);
    out1.close();

    fixLabels();

    ofstream out2("preLinking-program.txt");
    dumpCode(out2);
    out2.close();


    link();
}


void Program::link()
{
    // Calculate the addresses for labels
    map<string, int> labelValues;
    int actualI = 1;
    for ( unsigned  int i = 0; i < ralProgram.size(); i++ )
    {
		// Enter if it's not a comment and contains a label
    	if ( ralProgram[i].find(";") != 0 ) {
	        if ( ralProgram[i].find(":") != string::npos ) {
	            // First enter into map
	            labelValues[ralProgram[i].substr(0,ralProgram[i].find(":"))] = actualI;

	            // Next delete from that one
	            ralProgram[i] = ralProgram[i].substr(ralProgram[i].find(":") + 1);
                i--;
	        } else {
                actualI++;
            }
    	}
    }

    // Handle "LINE"
    int actualK = 1;
    for ( unsigned int k = 1; k < ralProgram.size(); k++ ) {
        if(ralProgram[k].find(";") != 0  ) {
            if ( ralProgram[k].find(LINE) != string::npos) {
                string address = Number::getConstant(constantValues, actualK + 3);
                ralProgram[k] = ralProgram[k].substr(0, ralProgram[k].find(" ") + 1) + address;
            }
            actualK++;
        }

    }



    // Loop through the symbol table three times, giving each addresses
    int counter = 1;

    // Assign globals an address
    constAddresses[FP] = SymbolDetails(0, "CONSTANT", counter++);
    constAddresses[TEMP] = SymbolDetails(0, "CONSTANT", counter++);
    constAddresses[FPB] = SymbolDetails(0, "CONSTANT", counter++);
    constAddresses[NEXT_FP] = SymbolDetails(5 + constantValues.size() + FT.size(), "CONSTANT", counter++);


    for (map<int, string>::iterator a = constantValues.begin(); a != constantValues.end(); a++) {
        //cout << "Constant: " << a->second << endl;
        constAddresses[a->second] = SymbolDetails(a->first, "CONSTANT", counter++);
    }

    // Loop through FP and set constants for the size
    for(map<string, Proc*>::iterator iter = FT.begin(); iter != FT.end(); iter++) {
        Proc* P = iter->second;
        constAddresses["[" + iter->first + "]"] = SymbolDetails(P->getARSize(), "CONSTANT", counter++);
    }

    // Time to actually do the linking in the program
    int actualJ = 1;
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
	            		cout << "Error: unknown variable: " << tempVar << endl;
	            		exit(1);
	            	}
	                int t2 = constAddresses[tempVar].getAddress();
	                string s2;
	                stringstream out2;
	                out2 << t2;
	                s2 = out2.str();
	                ralProgram[j] = ralProgram[j].substr(0, ralProgram[j].find(" ") + 1) + s2;
	            }
	        }
	        actualJ++;
    	}
    }
}
