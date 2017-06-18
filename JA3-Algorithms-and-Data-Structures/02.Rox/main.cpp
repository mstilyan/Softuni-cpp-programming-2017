#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, char>::iterator map_iterator;

int main(int argc, char* argv[])
{
	std::unordered_map < std::string, char > DNAs;
	map_iterator itr;
	char a, b, c, d, e;

	do {
		std::cin >> a >> b >> c >> d >> e;
		std::string str = "";
		str += a; str += b; str += c; str += d; str += e;

		itr = DNAs.find(str);
		if (itr == DNAs.end())
			DNAs.insert(std::pair < std::string, char>(str, 'a'));
		else
			itr->second = 'b';

		str = "";
	} while (std::cin.peek() != '.');

	for (itr = DNAs.begin(); itr != DNAs.end(); ++itr)
		if (itr->second == 'a')
			break;

	std::cout << itr->first << std::endl;
	return 0;
}
