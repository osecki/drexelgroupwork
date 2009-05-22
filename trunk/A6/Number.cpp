#include "Number.h"
#include <map>
#include <sstream>

Number::Number(int value)
{
    value_ = value;
}

int Number::eval(map<string,int> NT) const
{
    return value_;
}

string Number::toString(map<string,int> NT) const {
    std::stringstream s;
    s << value_;
    return s.str();
}