#include "ComputationMachine.h"
#include <iostream>
#include <string>

std::stack<int> ComputMachine::stk;

void ComputMachine::concat()
{
	std::string b = std::to_string(stk.top());
	stk.pop();
	std::string a = std::to_string(stk.top());
	stk.pop();
	stk.push( atoi( (a + b).c_str() ) );
}

void ComputMachine::discard()
{
	stk.pop();
}

void ComputMachine::subtract()
{
	int a = stk.top();
	stk.pop();
	int b = stk.top();
	stk.pop();
	stk.push(a - b);
}

void ComputMachine::insert(const int& value)
{
	stk.push(value);
}

void ComputMachine::sum()
{
	int a = stk.top();
	stk.pop();
	int b = stk.top();
	stk.pop();

	stk.push(a + b);
}


void ComputMachine::print()
{
	std::stack<int> rev;
	while (!stk.empty()) 
	{
		rev.push(stk.top());
		stk.pop();
	}
	while (!rev.empty()) 
	{
		std::cout << rev.top() << std::endl;
		rev.pop();
	}
}
