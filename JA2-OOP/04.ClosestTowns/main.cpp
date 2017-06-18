#include "Vector2D.h"

#include <iostream>
#include <string>
#include <vector>

struct Pair {
    std::string cityName;
    Vector2D coordinates;
    Pair(std::string cityName, Vector2D coordinates) : 
        cityName(cityName),
        coordinates(coordinates){};
};

typedef std::vector<Pair>::iterator vec_iterator;

int main(int argc, char const *argv[]) {
    int citiesCount, x, y;
    double shortestDistance;
    std::string closestCities;
    std::string nameOfCity;

    std::vector<Pair> cities;
    std::cin >> citiesCount;
    for (size_t i = 0; i < citiesCount; i++) {
        std::cin >> nameOfCity >> x >> y;
        cities.push_back(Pair(nameOfCity, Vector2D(x, y)));
    }

    shortestDistance = (cities.begin()->coordinates - (++cities.begin())->coordinates).getLength();
    closestCities = cities.begin()->cityName + "-" + (++cities.begin())->cityName;

    for(vec_iterator itr1 = cities.begin(); itr1 != cities.end(); itr1++)
        for(vec_iterator itr2 = itr1 + 1; itr2 != cities.end(); itr2++)
            if ((itr1->coordinates - itr2->coordinates).getLength() < shortestDistance){
                closestCities = itr1->cityName + "-" + itr2->cityName;
                shortestDistance = (itr1->coordinates - itr2->coordinates).getLength();
            }

    std::cout << closestCities << std::endl;
    return 0;
}
