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
}

void Program::fixLabels()
{
	// Make sure no labels are on a line of their own
	for ( int i = 0; i < ralProgram.size(); i++ )
	{
		cout << "HERE" << endl;
		if ( ralProgram[i].find(":") == ralProgram[i].length() - 1)
		{
			cout << "here"<< endl;
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
	for ( int i = 0; i < ralProgram.size() - 1; i++ )
	{
		//cout << ralProgram[i].find("ST") << "-" << ralProgram[i+1].find("LD") << "-" << (ralProgram[i].substr(3)).compare(ralProgram[i+1].substr(3)) << endl;
		if ( ralProgram[i].find("ST") == 0 && ralProgram[i+1].find("LD") == 0 &&
				 (ralProgram[i].substr(3)).compare(ralProgram[i+1].substr(3)) == 0 )
		{
			// Delete the Load
			vector<string>::iterator temp = ralProgram.begin() + i;
			ralProgram.erase(temp + 1, temp + 2);
		}
	}
}

void Program::link()
{
	// TODO
}

void Program::compile()
{
	translate();

	if (OPTIMIZE)
	{
		optimize();
	}

	fixLabels();

	link();
}

