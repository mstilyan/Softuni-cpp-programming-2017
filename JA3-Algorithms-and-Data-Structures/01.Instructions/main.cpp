#include <iostream>
#include <string>
#include "ComputationMachine.h"

int main(int argc, char* argv[])
{
	std::string input;

	std::cin >> input;
	while(input != "end")
	{
		if (input == "sum")
			ComputMachine::sum();
		else if (input == "subtract")
			ComputMachine::subtract();
		else if (input == "concat")
			ComputMachine::concat();
		else if (input == "discard")
			ComputMachine::discard();
		else
			ComputMachine::insert(atoi(input.c_str()));

		std::cin >> input;
	}

	ComputMachine::print();
	return 0;
}
