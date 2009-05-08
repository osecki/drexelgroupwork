#ifndef ASSIGNSTMT_H
#define ASSIGNSTMT_H

#include <map>
#include <string>
#include "Stmt.h"
#include "Expr.h"

class Proc;

using namespace std;

class AssignStmt: public Stmt
{
public:
    AssignStmt(string name="", Expr *E=NULL);
    ~AssignStmt() {delete E_;};
		// Changed environment table here
		void eval(map<string,Element*> &NT) const;
private:
    string name_;
    Expr* E_;
};

#endif
