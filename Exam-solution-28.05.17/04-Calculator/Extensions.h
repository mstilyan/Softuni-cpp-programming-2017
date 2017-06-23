#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <memory>

#include "InputInterpreter.h"
#include "CalculationEngine.h"

#include "DivisionOperation.h"
#include <stack>
#include "MemoryOperations.h"

class OperationInterpreter : public InputInterpreter
{
private:
	CalculationEngine& eng;

public:

	OperationInterpreter(CalculationEngine& eng) : InputInterpreter(eng), eng(eng){}

	std::shared_ptr<Operation> getOperation(std::string operation) override {
		if (operation == "*") {
			return std::make_shared<MultiplicationOperation>();
		}
		else if (operation == "/") {
			return std::make_shared<DivisionOperation>();
		} else if (operation == "ms")
		{
			return  std::make_shared<MemorySave>();
		}
		else if (operation == "mr")
		{
			return  std::make_shared<MemoryRecall>();
		}

		return std::shared_ptr<Operation>(nullptr);
	}
};
	 
std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
    return std::make_shared<OperationInterpreter>(engine);
}

#endif // EXTENSIONS_H
