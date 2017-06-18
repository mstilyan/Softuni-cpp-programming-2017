#include <iostream>
#include "Array.h"

int main() 
{
	short L, H, neededCount;
	std::cin >> L >> H >> neededCount;

	size_t pos = 0, index = 0;
	uint64_t currLowLimit = arr[pos] * L;;
	uint64_t result = 0;

	while (currLowLimit <= arr[SIZE - 1])
	{
		currLowLimit = arr[pos] * L;
		while (index < SIZE && arr[index] < currLowLimit) ++index;
		if (index + neededCount - 1 < SIZE && arr[index + neededCount - 1] <= arr[pos] * H) ++result;
		++pos;
	}

	std::cout << result << std::endl;
	return 0;
}