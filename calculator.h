#pragma once
#include <vector>
#include <iostream>

enum MathType {prime, gcd, binary};


class Math {
    int first, second;
    MathType calcType;
    std::string answer;
    
    public:
    Math (MathType math, std::string ans, int a, int b=0);

    void printMath();

};


class CalcStorage {
    std::vector<Math*>* calculations;
    int count;

    public:
    CalcStorage ();

    void addOperation(Math* toAdd);
    void printOperations();
    void destroy();
};
