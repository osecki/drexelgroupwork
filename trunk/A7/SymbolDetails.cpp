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
	this->type_ = "Unknown";
	this->address_= -1;
}

int SymbolDetails::getValue() {
	return value_;
}

string SymbolDetails::getType() {
	return type_;
}

int SymbolDetails::getAddress() const {
	return address_;
}

void SymbolDetails::setValue(int v) {
	this->value_ = v;
}

void SymbolDetails::setType(string t) {
	this->type_ = t;
}

void SymbolDetails::setAddress(int a) {
	this->address_ = a;
}


bool operator<(const SymbolDetails & left,  const SymbolDetails & right){
	return left.getAddress() < right.getAddress();
}
