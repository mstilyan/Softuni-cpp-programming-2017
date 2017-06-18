#include <iostream>
#include <algorithm>

struct Location
{
	int x, y;
	int getDistance(const Location& other)
	{
		return abs(x - other.x) + abs(y - other.y);
	}
};

int main(int argc, char* argv[])
{
	int neededMineralsCount;
	int totalMinerals;
	unsigned long long totalTime = 0;
	Location commandCenter;
	Location mineral;

	std::cin >> neededMineralsCount;
	std::cin >> commandCenter.x >> commandCenter.y;
	std::cin >> totalMinerals;

	int* distances = new int[totalMinerals];
	for (size_t i = 0; i < totalMinerals; ++i)
	{
		std::cin >> mineral.x >> mineral.y;
		distances[i] = mineral.getDistance(commandCenter);
	}

	std::sort(distances, distances + totalMinerals);
	for (size_t i = 0; i < neededMineralsCount; ++i)
		totalTime += (distances[i] * 2);
		
	std::cout << totalTime << std::endl;

	delete[] distances;
	return 0;
}
