#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
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
	cout << "Symbol Table" << endl;
	cout << "Symbol		Value		Type		Address" << endl;
	for (map<string, SymbolDetails>::iterator sti = symbolTable.begin(); sti!=symbolTable.end(); sti++) {
		cout<<(*sti).first<<"		"<<(*sti).second.getValue() << "		" << (*sti).second.getType() << "		" << (*sti).second.getAddress() << endl;
	}

  cout << endl;
	cout << "Program below:" << endl;
	cout << endl;

  for (int i=0; i< ralProgram.size(); i++)
	     cout << ralProgram[i] << endl;

	ofstream progFile;
	progFile.open ("prog.txt");
	for (int i=0; i< ralProgram.size(); i++)
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

	// Output Variables to file
	for (map<string, SymbolDetails>::iterator b = symbolTable.begin(); b != symbolTable.end(); b++) {
		  if ( ((*b).second.getType()).compare("Variable") == 0 )
			{
				memFile << (*b).second.getAddress() << "  " << (*b).second.getValue() << endl;
			} 
	}

	// Output Temporaries to file
	for (map<string, SymbolDetails>::iterator c = symbolTable.begin(); c != symbolTable.end(); c++) {
	  if ( ((*c).second.getType()).compare("Temporary") == 0 )
		{
			memFile << (*c).second.getAddress() << "  " << (*c).second.getValue() << endl;
		} 
	}

	memFile.close();

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

void Program::optimize()
{
	// Iterate through, looking for Store followed by Load with same variable.
	// If this is found, Delete the load
	for ( int i = 0; i < ralProgram.size() - 1; i++ )
	{
		if ( ralProgram[i].find("STA") == 0 && ralProgram[i+1].find("LDA") == 0 &&
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
	// Loop through the symbol table three times, giving each addresses
	int counter = 1;

	// Assign Constants an address
	for (map<string, SymbolDetails>::iterator a = symbolTable.begin(); a != symbolTable.end(); a++) {
		    if ( ((*a).second.getType()).compare("Constant") == 0 )
				{
					(*a).second.setAddress(counter);
					counter++;
				}
	}

	// Assign Variables an address
	for (map<string, SymbolDetails>::iterator b = symbolTable.begin(); b != symbolTable.end(); b++) {
		  if ( ((*b).second.getType()).compare("Variable") == 0 )
			{
				(*b).second.setAddress(counter);
			  counter++;
			} 
	}

	// Assign Temporaries an address
	for (map<string, SymbolDetails>::iterator c = symbolTable.begin(); c != symbolTable.end(); c++) {
	  if ( ((*c).second.getType()).compare("Temporary") == 0 )
		{
			(*c).second.setAddress(counter);
			counter++;
		} 
	}

	// Calculate the addresses for labels
	map<string, int> labelValues;
	for ( int i = 0; i < ralProgram.size(); i++ )
	{
		if ( ralProgram[i].find(":") != string::npos )
		{
			// First enter into map
			labelValues[ralProgram[i].substr(0,ralProgram[i].find(":"))] = i + 1;

			// Next delete from that one
			ralProgram[i] = ralProgram[i].substr(ralProgram[i].find(":") + 1);
		}
	}

	// Time to actually do the linking in the program
	for ( int j = 0; j < ralProgram.size(); j++ )
	{
		string tempVar = ralProgram[j].substr(ralProgram[j].find(" ") + 1);

		if ( ralProgram[j].find("HLT") == string::npos)
		{
		// Need to decide if we look in symbolTable or labelTable
		if ( (tempVar.substr(0, 1)).compare("L") == 0 )
		{
			int t1 = labelValues[tempVar];
			string s1;
			stringstream out1;
			out1 << t1;
			s1 = out1.str();
			ralProgram[j] = ralProgram[j].substr(0, ralProgram[j].find(" ") + 1) + s1;
		}
		else
		{
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

