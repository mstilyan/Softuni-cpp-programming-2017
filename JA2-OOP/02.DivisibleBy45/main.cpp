#include <iostream>
#include <string>
#include "BigInt.h"

bool isDivisibleByFortyFive(const BigInt& num){
    std::string digits = num.getDigits();
    int totalSumOfDigits = 0;
    int lastDigit = digits.at(digits.length() - 1) - '0';

    for(char i : digits){
        totalSumOfDigits += (i - '0');
    }

    return !(totalSumOfDigits % 9) && !(lastDigit % 5);
}

int main() {
    std::string from, to;
    std::getline(std::cin, from);
    std::getline(std::cin, to);

    const BigInt ONE(1);
    const BigInt FORTY_FIVE(45);
    BigInt startingBigInt(from);
    BigInt onePastEndBigInt(to);

    bool foundDivisibleBigInt = false;

    while(startingBigInt < onePastEndBigInt){
        if (foundDivisibleBigInt){
            std::cout << startingBigInt << std::endl;
            startingBigInt += FORTY_FIVE;
            continue;
        } else if (isDivisibleByFortyFive(startingBigInt)){
            std::cout << startingBigInt << std::endl;
            foundDivisibleBigInt = true;
            startingBigInt += FORTY_FIVE;
        } else {
            startingBigInt += ONE;
        }
    }

    return 0;
}
