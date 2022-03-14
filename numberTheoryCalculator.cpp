#include "euclid.h"
#include <iostream>
#include <string>
#include <iostream>

void printOptions() {
    std::cout << "1 Check if prime\n2 Find Greates Common Divisor\n" 
    << "3 Get binary representation\n4 Exit\n0 Print calculation history\n";
}

int main() {

    EuclidieanCalculator* calc = new EuclidieanCalculator;
    std::cout << "Welcome to my weird calculator!\n";

    while (true) {
        int input;
        std::cout << "Please enter the number to pick from the following options:\n";
        printOptions();

        input = calc->getValue();
        if (input == 4) {
            break;
        }
        switch (input) {
            case 0:
                calc->printHistory();
                break;
            case 1:
                calc->getPrime();
                break;
            case 2:
                calc->getEuclid();
                break;
            case 3:
                calc->printBin();
                break;
        }
    }
}