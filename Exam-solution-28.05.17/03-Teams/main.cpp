#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;
typedef std::string TeamName;
typedef std::string PlayerName;

int main(int argc, char* argv[])
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	int numberOfTeams;
	unordered_map<TeamName, int> teamWins;
	map<PlayerName, vector<TeamName> > playerTeams;

	std::cin >> numberOfTeams;
	for (int i = 0; i < numberOfTeams; ++i)
	{
		TeamName name;
		int playersCount;
		std::cin >> name >> playersCount;
		teamWins[name] = 0;

		for (int i = 0; i < playersCount; ++i)
		{
			PlayerName plr;
			std::cin >> plr;
			playerTeams[plr].push_back(name);
		}
	}

	int games;
	std::cin >> games;

	for (int i = 0; i < games; ++i)
	{
		TeamName winner;
		std::cin >> winner;
		++teamWins[winner];
	}

	for (auto pair : playerTeams)
	{
		int wins = 0;
		for (auto team : pair.second)
		{
			wins += teamWins[team];
		}

		std::cout << wins << " ";
	}

	return 0;
}
