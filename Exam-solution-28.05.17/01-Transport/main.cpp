#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::vector<int> times;
	int num, time, minutes, hours;
	do
	{
		std::cin >> num;
		hours = num / 100;
		minutes = num % 100;
		times.push_back(hours * 60 + minutes);
	}
	while (std::cin.peek() != '\n');
	std::cin >> time;
	minutes = time % 100;
	hours = time / 100;
	time = hours * 60 + minutes;

	std::sort(times.begin(), times.end());
	for (int i = times.size() - 1; i >= 0; --i)
	{
		if (times[i] <= time)
		{
			std::cout << time - times[i];
			return 0;
		}
	}

	std::cout << 0;
	return 0;
}
