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

void Program::dump()
{
	/*
    cout << "Symbol Table" << endl;
    cout << "Symbol\t\tValue\t\tType\t\tAddress" << endl;
    for (map<string, SymbolDetails>::iterator sti = symbolTable.begin(); sti!=symbolTable.end(); sti++) {
        cout<<(*sti).first<<"\t\t"<<(*sti).second.getValue() << "\t\t" << (*sti).second.getType() << "\t\t" << (*sti).second.getAddress() << endl;
    }

    cout << endl;
    cout << "Program below:" << endl;
    cout << endl;
	*/
	
	
	
    for (unsigned int i=0; i< ralProgram.size(); i++)
        cout << ralProgram[i] << endl;
    
	/*
    ofstream progFile;
    progFile.open ("prog.txt");
    for (unsigned int i=0; i< ralProgram.size(); i++)
        progFile << ralProgram[i] << endl;
    progFile.close();

    cout << endl;
    cout << "Program file created in prog.txt:" << endl;
    cout << "Memory file created in mem.txt" << endl;

    ofstream memFile;
    memFile.open ("mem.txt");

    // Output Constants to file
    for (map<string, SymbolDetails>::iterator a = symbolTable.begin(); a != symbolTable.end(); a++) {
        if ( ((*a).second.getType()).compare("Constant") == 0 )
        {
            memFile << (*a).second.getAddress() << "  " << (*a).second.getValue() << endl;
        }
    }

    memFile.close();
	*/
}

void Program::translate()
{
    // Treat main as a function
    p = new Proc(new list<string>(), SL_);

    // Add the function to the function table
    d = new DefineStmt("main", p);
    d->translate(constantValues, symbolTable, ralProgram, FT);
	

	
	cout << "There are " << constantValues.size() << " constants" << endl;
	
	// Constants + TEMP + SP + thisConstant
	int globalMemory = constantValues.size() + 4;
	ralProgram.push_back("LD " +Number::getConstant(constantValues, globalMemory));
	ralProgram.push_back("ST SP");
	//FunCall("main", new list<Expr*>()).translate();
	ralProgram.push_back("; CALL MAIN");
	//ralProgram.push_back("halt:");
	ralProgram.push_back("HLT");
	

	// Now print rest of the procs
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
    
    // Fix up Procs with addresses
    for(map<string, Proc*>::iterator iter = FT.begin(); iter != FT.end(); iter++) {
    	Proc* p = iter->second;
    	//p->link(constantValues);
    }

    if (OPTIMIZE) {
        optimize();
    }

    //fixLabels();

    //link();
}


void Program::link()
{
    //p->link(constantValues, symbolTable, ralProgram, FT);
}
