#ifndef EXECUTE_PROCESS_HPP
#define EXECUTE_PROCESS_HPP

#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;


class execute_process
{
private:
    /* data */
public:

    float result_per_file(string path);
    float result_per_process(string process_path);
    execute_process( );
    ~execute_process();
};

execute_process::execute_process(/* args */)
{
}

execute_process::~execute_process()
{
}



#endif