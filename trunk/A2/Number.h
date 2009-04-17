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
    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;
    virtual string toString() const;
private:
    int value_;
};

#endif
