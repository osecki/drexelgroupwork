/*
 * file:  program.h (contains declarations of Program, StmtList, Stmt, Expr)
 * Author: Jeremy Johnson
 * Date: 2/05/07
 *
 * Description:
 */
#include <iostream>
#include <string>
#include <map>
#include <list>
#include "List.h"
#include "Proc.h"


using namespace std;

// forward declarations
// StmtList used by IfStmt and WhileStmt which are Stmt
// Proc which contains StmtList used in Expr, Stmt, StmtList
class StmtList;
class Proc;

