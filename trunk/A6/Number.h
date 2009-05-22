#ifndef NUMBER_H
#define NUMBER_H

#include <map>
#include <string>

class Number : public Expr
{
public:
    Number(int value = 0);
    virtual int eval(map<string,int> T) const;
private:
    int value_;
};

#endif
