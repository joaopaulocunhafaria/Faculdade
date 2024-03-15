#ifndef MINMAX_HPP
#define MINMAX_HPP
#include <iostream>
 
using namespace std;
 
class minMax
{
private:
public:
    minMax();
    void manage_executions();
    int *creat_random_array(int n);
    int *create_crescent_sort_array(int n);
    int *create_decrescent_sort_array(int n);
    void minMax1(int *vet, int n);
    void minMax2(int *vet, int n);
    void minMax3(int *vet, int n);
    ~minMax();
};

#endif
