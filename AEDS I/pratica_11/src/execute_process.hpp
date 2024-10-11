#ifndef EXECUTE_PROCESS_HPP
#define EXECUTE_PROCESS_HPP

#include <iostream>
#include <fstream>
#include <chrono>
#include <iostream> 
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


class execute_process
{
private:
    int quantity;
public:

    float result_per_file(string path);
    float result_per_process(string process_path);
    void run();
    execute_process(int quantity);
    ~execute_process();
};
 


#endif