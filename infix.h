/*
 * infixpost.h
 *
 *  Created on: Jul 24, 2015
 *      Author: bharu_sathya
 */

#ifndef INFIXPOST_H_
#define INFIXPOST_H_

#include<iostream>
#include<cassert>
#include<string>
using namespace std;

#include"myStack.h"


template <class Type>
class intopost: public stackType<Type>{

public:
	void getinfix(string infix);
	void showinfix() const;
	void showpostfix() const;
	void converttopostfix();
	bool precedence(const char op1, const char op2);
	bool isoperator(const char c);
	intopost();
	~intopost();

private:
	string infix;
	string pfx;
};

template <class Type>
void intopost<Type>:: getinfix(string infx)
{


	infix=infx;


}

template <class Type>
void intopost<Type>::showinfix() const{
	cout<<"The Infix expression is: "<<infix;
}


template <class Type>
void intopost<Type>::showpostfix() const{
	cout<<"\nThe postfix expression is: "<<pfx;
}


template <class Type>
void intopost<Type>:: converttopostfix()
{

	infix.insert(infix.length(),")");
	infix.insert(0,"(");
	stackType<char> mystack(10);

	unsigned int i=0;

	for(i=0;i<infix.length();i++)
	{
	if(isoperator(infix[i]))			//operator
		{
			if(isoperator(mystack.top()))
				{

				if(precedence(infix[i],mystack.top()))
					{
					while(mystack.top()!='(')
						{
						pfx=pfx+mystack.top();
						mystack.pop();
						}
						mystack.push(infix[i]);
					}
					else
					{
						mystack.push(infix[i]);
					}
				}
			else
			{
				mystack.push(infix[i]);
			}

		}

		else if(infix[i]=='(')		//paratheses
		{
			mystack.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(mystack.top()!='(')
			{
				pfx=pfx+mystack.top();
				mystack.pop();
			}
			mystack.pop();
		}
		else						//opearands
		{
			pfx=pfx+infix[i];
		}

	}

	while(!mystack.isEmptyStack())
	{
		pfx=pfx+mystack.top();
		mystack.pop();
	}
}

template <class Type>
bool intopost<Type>::precedence(const char op1,const char op2)
{
	if((op1=='*'||op1=='/')&&(op2=='+' || op2=='-' ))
	{
		return false;
	}

	else if((op1=='+'||op1=='-')&&(op2=='*' || op2=='/' ))
	{
		return true;
	}

	else if((op1=='+'||op1=='-')&&(op2=='+' || op2=='-' ))
	{
		return true;
	}
	else if((op1=='*'||op1=='/')&&(op2=='*' || op2=='/' ))
	{
		return true;
	}

}

template <class Type>
bool intopost<Type>:: isoperator(const char c){
	if((c=='+')||(c=='-')||(c=='*')||(c=='/'))
		return true;
	else
		return false;
}

template <class Type>
intopost<Type>:: intopost(){

	pfx=" ";
}

template <class Type>
intopost<Type>::~intopost(){

}
#endif /* INFIXPOST_H_ */
