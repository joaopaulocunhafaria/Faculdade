#ifndef RESULTS_HPP
#define RESULTS_HPP
#include <iostream>
#include <fstream>

using namespace std;

class results
{

public:
    results();

   void  write_results(int methodoNumber,int size, string type,double time, string path);

};

#endif