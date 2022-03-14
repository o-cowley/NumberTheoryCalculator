#ifndef EUCLID
#define EUCLID
#include "calculator.h"

class EuclidieanCalculator {
    CalcStorage* storage;

    public:
    EuclidieanCalculator ();

    int getValue();

    void getEuclid();
    void printEuclid(int a, int b);

    void getPrime();
    bool isPrime(int a);

    void printBin();
    void decToBin(int a);

    void printHistory();
};

#endif