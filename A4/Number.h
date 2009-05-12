#ifndef NUMBER_H
#define NUMBER_H

#include "Element.h"
#include <map>
#include <string>

class Proc;

class Number : public Element
{
public:
    Number(int value = 0);
    // Added this helper method
		int getValue();
		// Needed for A2
    virtual int intp();
    virtual Element* eval(map<string,Element*> &NT) const;
    virtual string toString(map<string,Element*> NT) const;
private:
    int value_;
};

#endif