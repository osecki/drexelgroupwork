#ifndef NUMBER_H
#define NUMBER_H

#include "Element.h"
#include <map>
#include <string>

class Proc;

class Number : public Element
{
public:
    Number(int value = 0)
    {
	value_ = value;
    }

    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const
    {
	return value_;
    }

    virtual string toString() const
    {
      std::stringstream s;
      s << value_;
      return s.str();
    }

private:
    int value_;
};

#endif
