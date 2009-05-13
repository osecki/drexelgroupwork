#include "Number.h"
#include <map>
#include "Proc.h"
#include <sstream>


Number::Number(const Number& n) {
	cout << "CC(" << n.value_ << ")" << endl;
	this->value_ = n.value_;
}

Number::Number(int value)
{
    value_ = value;
}

Element* Number::eval(map<string,Element*> &NT) const
{
    return new Number(value_);
}

string Number::toString(map<string,Element*> NT) const {
    std::stringstream s;
    s << value_;
    return s.str();
}

// Needed for A2
int Number::intp(){
    return 1;
}

// Helper function
int Number::getValue() {
    return value_;
}
