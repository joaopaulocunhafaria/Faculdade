#ifndef TABLEMANAGER_HPP
#define TABLEMANAGER_HPP
#include <iostream>
#include <random>
#include "file_manager.hpp"

using namespace std;
  


class table_manager
{
private:
     
    string file_path;
    int executions;
    int table_size;
    char **table;
    char **table_aux;
    file_manager fileManager;


public:
    table_manager(  string  file_path, int executions);
    char **create_table();
    void next_table();
    void  print_table();
    void initializer();
    void alive(int i,int j);
    void dead(int i,int j);
    bool out_of_range(int i, int j);
    int count_neighbors(int i, int j);
    void free_memory();
    
};

 

#endif