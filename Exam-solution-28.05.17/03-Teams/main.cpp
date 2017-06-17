#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[])
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	int numberOfTeams;
	unordered_map<string, vector<string> > teamPlayers;
	unordered_map<string, int> teamWins;
	map<string, vector<string> > playerTeams;

	std::cin >> numberOfTeams;
	for (int i = 0; i < numberOfTeams; ++i)
	{
		string name;
		int playersCount;
		cin >> name >> playersCount;
		teamWins[name] = 0;
		std::vector<string> singleTeam(playersCount);

		for (int i = 0; i < playersCount; ++i)
		{
			string plr;
			std::cin >> plr;
			singleTeam.push_back(plr);
			playerTeams[plr].push_back(name);
		}

		teamPlayers[name] = singleTeam;
	}

	int games;
	cin >> games;

	for (int i = 0; i < games; ++i)
	{
		string winner;
		cin >> winner;
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
