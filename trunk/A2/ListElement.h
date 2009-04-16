/*
 * ListElement.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_

#include<iostream>
using namespace std;

class ListElement{
public:
	// this method must be overriden in the child class
	virtual string toString();
	void print() {
		cout<<toString()<<endl;
	}


};


#endif /* LISTELEMENT_H_ */
