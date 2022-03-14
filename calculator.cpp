#include "calculator.h"

Math::Math(MathType math, std::string ans, int a, int b) : first(a), second(b), calcType(math)
, answer(ans) {};

void Math::printMath() {
    if (calcType == gcd) {
        std::cout << "GCD of: " << first << " and " << second << "\n";
    } else if (calcType == prime) {
        std::cout << "Checked if: " << first << " was prime\n";
    } else {
        std::cout << "Found the binary representation of: " << first << "\n";
    }
    std::cout << answer;
};

CalcStorage::CalcStorage() : calculations(new std::vector<Math*>), count(0) {};

void CalcStorage::addOperation(Math* toAdd) {
    calculations->push_back(toAdd);
    count++;
};

void CalcStorage::printOperations() {
    for (int i = 0; i < count; i++) {
        ((*calculations)[i])->printMath();
    }
};

void CalcStorage::destroy() {
    for (int i = 0; i < count; i++) {
        delete ((*calculations)[i]);
    }
    delete calculations;
}