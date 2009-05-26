
#include <map>
#include <string>
#include "SymbolDetails.h"
using namespace std;

SymbolDetails::SymbolDetails(int value, string type, int address) {

	this->value_ = value;
	this->type_ = type;
	this->address_ = address;
}

SymbolDetails::SymbolDetails() {
	this->value_ = -1;
	this->type_ = "Unassigned";
	this->address_= -1;
}

int SymbolDetails::getValue() {
	return value_;
}

string SymbolDetails::getType() {
	return type_;
}
int SymbolDetails::getAddress() {
	return address_;
}
