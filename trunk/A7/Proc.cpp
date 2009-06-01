#include "Proc.h"
#include <list>
#include <map>
#include <string>
#include "StmtList.h"
#include <iostream>
#include <sstream>

Proc::Proc(list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    NumParam_ = PL->size();
}

int Proc::apply(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram)
{
// 	if (NumParam_ != EL->size()) {
// 		cout << "Param count does not match" << endl;
// 		exit(1);
// 	}

    // Get

    list<string>::iterator p;
    list<Expr*>::iterator e;
	//for (p = PL_->begin(), e = EL->begin(); p != PL_->end(); p++, e++)
		// NNT[*p] = (*e)->translate(NT,FT); TODO

	// evaluate function body using new name table and old function table

	//SL_->translate(NNT,FT); TODO
	//if ( NNT.find("return") != NNT.end() )
		//return NNT["return"];
	//else {
		cout << "Error:  no return value" << endl;
		exit(1);
	//}
    // Unreachable
    return -1;
}

string Proc::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram)
{
    // Simply write code but with ldi and sti calls
    SL_->translate(constantValues, symbolTable, ralProgram);
	return "";
}



void Proc::link(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram)
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