#include <map>
#include <iostream>
#include <iomanip>
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
	cout << setw(20) << right << "Symbol" << " | " << left << "Value" << endl;
	cout << setfill('-') << setw(22) << right << "+" << setw(20) << "-" << setfill(' ') << endl;

    //for (map<string,int>::iterator p = SymbolTable_.begin(); p != SymbolTable_.end(); p++) {
    //    cout << setw(20) << right << p->first << " | " << left << p->second << endl;
    //}


	cout<<"symbol table	"<<endl;
	cout<<"------------"<<endl;
	for (map<string, SymbolDetails>::iterator sti = symbolTable.begin(); sti!=symbolTable.end(); sti++) {
		cout<<(*sti).first<<"	"<<(*sti).second.type_<<endl;
	}

	cout<<"constant table"<<endl;
	cout<<"--------------"<<endl;
	for (map<int, string>::iterator cti = constantValues.begin(); cti!=constantValues.end(); cti++) {
		cout<<(*cti).first<<"	"<<(*cti).second<<endl;
	}
}

/*void Program::eval()
{
    SL_->eval(SymbolTable_);
}*/

void Program::translate() {

	SL_->translate(constantValues, symbolTable);
}
