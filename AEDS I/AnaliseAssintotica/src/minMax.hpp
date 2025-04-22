#ifndef MINMAX_HPP
#define MINMAX_HPP
#include <iostream>
#include <chrono>
#include <random>
#include "results.hpp"

using namespace std;

class minMax
{
private:
    results r;

public:
    minMax();
    void manage_executions();
    int *creat_random_array(int n);
    int *create_crescent_sort_array(int n);
    int *create_decrescent_sort_array(int n);
    double minMax1(int *vet, int n);
    double minMax2(int *vet, int n);
    double minMax3(int *vet, int n);
};

#endif
