#ifndef SYMBOLDETAILS_H
#define SYMBOLDETAILS_H

#include <string>
using namespace std;

class SymbolDetails
{
public:
	SymbolDetails(int value, string type, int address);
	SymbolDetails();
	
	int getValue();
	string getType();
	int getAddress() const;
	void setValue(int v);
	void setType(string t);
	void setAddress(int a);

private:
  int value_;
  string type_;
  int address_;
};

 
bool operator<(const SymbolDetails & left, const SymbolDetails & right);

#endif
