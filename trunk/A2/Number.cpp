#include "Number.h"
#include <map>
#include "Proc.h"
#include <sstream>

Number::Number(int value)
{
    value_ = value;
}

int Number::eval(map<string,int> NT, map<string,Proc*> FT) const
{
    return value_;
}

string Number::toString() const {
    std::stringstream s;
    s << value_;
    return s.str();
}

