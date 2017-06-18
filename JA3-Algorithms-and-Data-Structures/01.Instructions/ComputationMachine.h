#ifndef COMPUTATION_MACHINE_H
#define COMPUTATION_MACHINE_H
#include <stack>

class ComputMachine
{
private:
	static std::stack<int> stk;
public:
	static void insert(const int& value);
	static void sum();
	static void subtract();
	static void concat();
	static void discard();
	static void print();
};

#endif //COMPUTATION_MACHINE_H
