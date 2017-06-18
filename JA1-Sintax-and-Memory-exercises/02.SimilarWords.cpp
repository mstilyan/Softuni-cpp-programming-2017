#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <string>
using namespace std;

int areSimilar(string word, string compBase, double percentage)
{
	if (word.length() != compBase.length() || word[0] != compBase[0])
		return  0;

	int countSame = 0;
	for (size_t i = 0; i < compBase.length(); i++)
		if (compBase[i] == word[i])
			countSame++;

	double result = static_cast<float>(countSame * 100) / word.length();
	return result > percentage ||
		std::fabs(result - percentage) < std::numeric_limits<double>::epsilon();
}

int main(int argc, char* argv[])
{
	string text, compBase;
	int countSimilar = 0;
	double percentage;

	getline(std::cin, text);
	cin >> compBase >> percentage;
	for (char& it : text)
		if (it < 'a' || it > 'z')
			it = ' ';

	stringstream ss(text);
	while (ss >> text)
		if (areSimilar(text, compBase, percentage))
			countSimilar++;

	std::cout << countSimilar << endl;
	return 0;
}
