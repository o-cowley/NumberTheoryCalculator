#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#include "euclid.h"

using namespace std;

EuclidieanCalculator::EuclidieanCalculator () : storage(new CalcStorage()) {};

void EuclidieanCalculator::getEuclid() {
    int first, second;

    std::cout << "What is the first number? \n";
    first = getValue();

    std::cout << "What is the second number? \n";
    second = getValue();

    if (first > second) {
        printEuclid(first, second);
    } else {
        printEuclid(second, first);
    }
}

void EuclidieanCalculator::printEuclid(int a, int b) {
    vector<int> vec;
    int first, second, remainder, multiplicand;
    first = a;
    second = b;
    bool check = true;

    while (check) {
        remainder = first % second;
        multiplicand = (first - remainder) / second;
        cout << first << " = " << second << "*" << multiplicand << " + " << remainder << "\n";

        vec.push_back(first);
        vec.push_back(second);
        vec.push_back(remainder);

        if (remainder == 0) {
            check = false;
            cout << "The greatest common factor is: " << second << "\n";
            if (second == 1) {
                cout << "These numbers are relatively prime!\n";
            }

            std::string ans = "The answer was: " + std::to_string(second) + "\n";
            Math* toAdd = new Math(gcd, ans, a, b);
            storage->addOperation(toAdd);
        }
        first = second;
        second = remainder;
    }
}

int EuclidieanCalculator::getValue() {
    string input;
    int toReturn;
    getline(cin, input);
    stringstream(input) >> toReturn;

    return toReturn;
}

void EuclidieanCalculator::getPrime() {
    int first;
    std::string answer;
    

    std::cout << "What number would you like to check? \n";
    first = getValue();
    bool result = isPrime(first);
    if (result) {
        cout << "YEP! That number is prime!\n";
        answer = "Yes it is prime!\n";
    } else {
        cout << "Sorry, that's not prime :(\n";
        answer = "No, it is not prime\n";
    }

    Math* toAdd = new Math(prime, answer, first);
    storage->addOperation(toAdd);
}

bool EuclidieanCalculator::isPrime(int a) {
    bool is = true;

    int check1, check2, counter;

    int midpoint = sqrt(a) + 1;
    
    if (a % 2 == 0) {
        is = false;
    } else if (a % 3 == 0) {
        is = false;
    } else {
        check1 = 5, check2 = 7, counter = 2;
    
        while (check1 < midpoint) {
            if (check1 % a == 0) {
                is = false;
                break;
            }
            if (check2 % a == 0 & check2 < midpoint) {
                is = false;
                break;
            }
            check1 = 6 * counter - 1, check2 = 6 * counter + 1, counter++;
        }
    }
    return is;
}

void EuclidieanCalculator::printBin() {
    int first;

    std::cout << "What number would you like to see in binary? \n";
    first = getValue();

    decToBin(first);
}

void EuclidieanCalculator::decToBin(int a) {
    string str;

    int toCalc = a;

    while (toCalc > 0) {
        if (toCalc % 2 == 0) {
            str.insert(str.begin(), '0');
        } else {
            str.insert(str.begin(), '1');
        }
        toCalc >>= 1;
    }
    cout << str << "\n";

    str = "In binary it is: " + str + "\n";
    Math* toAdd = new Math(binary, str, a);
    storage->addOperation(toAdd);
}

void EuclidieanCalculator::printHistory() {
    storage->printOperations();
}