#include "Number.h"
#include <map>

Number::Number(int value)
{
    value_ = value;
}

int Number::eval(map<string,int> T) const
{
    return value_;
}

