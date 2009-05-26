#include "Number.h"
#include <map>

Number::Number(int value)
{
    value_ = value;
}

/*int Number::eval(map<string,int> T) const
{
    return value_;
}*/

string Number::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const{

	// look into the constant table for the Number. If it is there
	// get the value from it otherwise create the new Number and add to the symbol table
	string newConstant;
	Program p;
	//if(constantValues!=NULL)
	map<int, string>::iterator location = constantValues.find(value_);
	if ( location!=constantValues.end() ) {

		newConstant = constantValues[value_];

	}else {

		stringstream outConst;

		outConst << p.constantCounter;
		newConstant = CONSTANT + outConst.str();

		// increment the counter for the next constant
		p.constantCounter++;

		// add this into the constant table
		constantValues[value_] = newConstant;

		// then add to the symbol table
		SymbolDetails newSymbolConst(-1,"Constant",-1);

		symbolTable[newConstant] = newSymbolConst;
		//cout<<"Not in the constant table creating new constant "<<newConstant<<"	"<<value_<<endl;
		//cout<<"Not in the symbol table creating new symbol for "<<newConstant<<endl;

	}

	cout<<"LD	"<<newConstant<<endl;
	// create new temporary variable then Store the new ident there
	string newTemp;
	stringstream outTemp;
	outTemp << p.temporaryVarCounter;

	newTemp = "T" + outTemp.str();

	p.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1,"Temporary",-1);
	symbolTable[newTemp] = newSymbolTemp;

	cout<<"ST	"<<newTemp<<endl;

	return newTemp;
}