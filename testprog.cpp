/*
 * testprog.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: bharu_sathya
 */




#include <iostream>
#include "myStack.h"
#include "infix.h"

using namespace std;


int main()
{
    string infix;
	intopost <string> expression; //Declare a stock object
	cout<<"Enter a string..";
	cin>>infix;
	expression.getinfix(infix);
	expression.showinfix();
	expression.converttopostfix();
	expression.showpostfix();
	}
