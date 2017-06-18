#include <iostream>
#include <sstream>
#include <string>
using namespace std;

std::string averageCol(string s1, string s2)
{
	stringstream ss;
	std::string result = "#", temp;
	unsigned int FirstColorInt, SecondColorInt;

	for (size_t pos = 1; pos < 6; pos += 2)
	{
		ss << s1.substr(pos, 2);
		ss >> std::hex >> FirstColorInt;
		ss.str(std::string());
		ss.clear();

		ss << s2.substr(pos, 2);
		ss >> std::hex >> SecondColorInt;
		ss.str(std::string());
		ss.clear();

		ss << std::hex << ((FirstColorInt + SecondColorInt) / 2);
		ss >> temp;
		ss.str(std::string());
		ss.clear();

		if (temp == "0")
			result += "00";
		else
			result += temp;
	}

	return result;
}

int main(int argc, char const *argv[]) {
	std::string firstCol;
	std::string secondCol;
	std::cin >> firstCol >> secondCol;

	std::cout << averageCol(firstCol, secondCol) << '\n';
	return 0;
}
