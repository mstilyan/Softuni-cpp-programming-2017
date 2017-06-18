#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

typedef int(*FOUR_ELEM_ARRAY_OF_FUNCTIONS[4])(int*, int, int);

int avg(int arr[], int startIndex, int endIndex)
{
	int avg = 0;
	for (size_t i = startIndex; i < endIndex; i++)
		avg += arr[i];

	return avg / (endIndex - startIndex);
}

int sum(int arr[], int startIndex, int endIndex)
{
	int sum = 0;
	for (size_t i = startIndex; i < endIndex; i++)
		sum += arr[i];

	return sum;
}

int min(int arr[], int startIndex, int endIndex)
{
	int min = arr[startIndex];
	for (size_t i = startIndex; i < endIndex; i++)
		if (min > arr[i])
			min = arr[i];

	return min;
}

int max(int arr[], int startIndex, int endIndex)
{
	int max = arr[startIndex];
	for (size_t i = startIndex; i < endIndex; i++)
		if (max < arr[i])
			max = arr[i];

	return max;
}

int main(int argc, char const *argv[])
{
	multimap<string, int> mapOfOperations;
	FOUR_ELEM_ARRAY_OF_FUNCTIONS operationsArray = {sum, avg, min, max};

	std::string line, operationNameKey;
	std::string intArrayAsString, result = "";
	int intArr[20] = { 0 };
	int pos = 0, operationIndex;
	int numOfOperations, startIndex, endIndex;

	getline(std::cin, intArrayAsString);
	cin >> numOfOperations;
	cin.ignore();

	stringstream ss(intArrayAsString);
	while (ss >> intArr[pos++]);
	ss.str(std::string());
	ss.clear();

	for (size_t i = 0; i < numOfOperations; i++)
	{
		getline(std::cin, line);
		ss << line;
		ss >> operationNameKey >> operationIndex;
		ss.str(std::string());
		ss.clear();

		mapOfOperations.insert(std::pair<string, int>(operationNameKey, operationIndex));
	}

	multimap<string, int>::iterator itr;
	pos = 0;

	while(true)
	{
		getline(std::cin, line);

		if (line == "end")
			break;
		if (!result.empty())
			result += ",";

		ss << line;
		ss >> operationNameKey >> startIndex >> endIndex;
		ss.str(std::string());
		ss.clear();

		if ((itr = mapOfOperations.find(operationNameKey)) != mapOfOperations.end())
		{
			result += itr->first + "(" + to_string(startIndex) + "," + to_string(endIndex) +
				")=" + to_string(operationsArray[itr->second](intArr, startIndex, endIndex));
		}
		pos++;
	}

	if (pos != 0)
		cout << "[" << pos << "]{" << result << "}\n";

	return 0;
}
