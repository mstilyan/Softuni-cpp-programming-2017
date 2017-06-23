#ifndef MEMORY_OPERATION_H
#define MEMORY_OPERATION_H

#include <vector>
#include "Operation.h"
#include <stack>

std::stack<int> memoryStack;

class MemorySave : public Operation {
	std::vector<int> operands;
	int result;
public:
	void addOperand(int operand) override {
		this->operands.push_back(operand);
		memoryStack.push(operand);

		if (this->isCompleted()) {
			this->result = this->operands[0];
		}
	}

	bool isCompleted() override {
		return this->operands.size() == 1;
	}

	int getResult() override {
		return this->result;
	}
};

class MemoryRecall : public Operation {
	int result;

protected:
	void addOperand(int operand) override{};

public:

	bool isCompleted() override {
		return !memoryStack.empty();
	}

	int getResult() override {
		if (this->isCompleted())
			this->result = memoryStack.top();

		memoryStack.pop();
		return this->result;
	}
};

#endif // MEMORY_OPERATION_H

