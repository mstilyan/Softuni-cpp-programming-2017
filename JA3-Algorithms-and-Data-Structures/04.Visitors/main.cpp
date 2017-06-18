#include <iostream>
#include <map>
#include <set>

struct User{
    std::string ID;
    std::string name;
    int age;
};

int main() {
    User user;
    std::map<std::string, int> uniqueNameCounter;
    std::map<int, int> uniqueAgeCounter;
    std::set<std::string> uniqueIDs;
    std::string operation;

    std::cin >> operation;
    while(operation != "end"){
        if (operation == "entry"){
            std::cin >> user.ID >> user.name >> user.age;
            if (uniqueIDs.find(user.ID) == uniqueIDs.end()){
                ++uniqueNameCounter[user.name];
                ++uniqueAgeCounter[user.age];
            }
            uniqueIDs.insert(user.ID);
        } else if (operation == "name"){
            std::cin >> user.name;
            std::cout << uniqueNameCounter[user.name] << std::endl;
        } else if (operation == "age"){
            std::cin >> user.age;
            //First age in the range [age1, age2)
            auto from = uniqueAgeCounter.lower_bound(user.age);
            std::cin >> user.age;

            int counter = 0;
            while(from->first < user.age && from != uniqueAgeCounter.end()) {
                counter += from->second;
                ++from;
            }

            std::cout << counter << std::endl;
        }

        std::cin >> operation;
    }

    return 0;
}