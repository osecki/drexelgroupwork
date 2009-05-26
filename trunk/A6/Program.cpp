#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Program.h"

int Program::constantCounter = 1;
int Program::temporaryVarCounter = 1;
int Program::labelCounter = 1;

Program::Program(StmtList *SL)
{
    //SymbolTable_.clear();
    constantValues.clear();// = new map<int, string>();
    symbolTable.clear();// = new map<string, SymbolDetails*>();

    SL_ = SL;
}

void Program::dump()
{
	cout << endl << endl;
	cout << setw(20) << right << "Symbol" << " | " << left << "Value" << right << "Type" << left << "Address" << endl;
	cout << setfill('-') << setw(22) << right << "+" << setw(20) << "-" << setfill(' ') << endl;

    //for (map<string,int>::iterator p = SymbolTable_.begin(); p != SymbolTable_.end(); p++) {
    //    cout << setw(20) << right << p->first << " | " << left << p->second << endl;
    //}

	cout<<"Symbol Table	"<<endl;
	cout<<"------------"<<endl;
	for (map<string, SymbolDetails>::iterator sti = symbolTable.begin(); sti!=symbolTable.end(); sti++) {
		cout<<(*sti).first<<"	"<<(*sti).second.getValue() << (*sti).second.getType() << (*sti).second.getAddress() << endl;
	}

	cout<<"constant table"<<endl;
	cout<<"--------------"<<endl;
	for (map<int, string>::iterator cti = constantValues.begin(); cti!=constantValues.end(); cti++) {
		cout<<(*cti).first<<"	"<<(*cti).second<<endl;
	}

	cout << "PRINTING OUT VECTOR:" << endl;

  for (int i=0; i< ralProgram.size(); i++)
	     cout << ralProgram[i] << endl;

	ofstream myfile;
	myfile.open ("output.txt");

	for (int i=0; i< ralProgram.size(); i++)
		myfile << ralProgram[i] << endl;
	
	myfile.close();
}

void Program::translate()
{
	SL_->translate(constantValues, symbolTable, ralProgram);
	
	// Add the HALT here, program has ended
	ralProgram.push_back("HLT");

	// Make sure no labels are on a line of their own
	for ( int i = 0; i < ralProgram.size(); i++ )
	{
		if ( ralProgram[i].find(":") == ralProgram[i].length() - 1)
		{
			// Combine elements
			ralProgram[i] = ralProgram[i] + ralProgram[i+1];
			
			// Delete second one
			vector<string>::iterator temp = ralProgram.begin() + i;
			ralProgram.erase(temp + 1, temp + 2);
		}
	}
}
