#include "Number.h"
#include <map>
#include "Proc.h"
#include <sstream>

Number::Number(int value)
{
    value_ = value;
}

Element* Number::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return new Number(value_);
}

string Number::toString() const {
    std::stringstream s;
    s << value_;
    return s.str();
}


int Number::intp(){
    return 1;
}

int Number::getValue() {
    return value_;
}
