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
    int table_size;
    char **table;
    file_manager fileManager;


public:
    table_manager(int table_size, string  file_path);
    char **create_table();
    void next_table();
    void  print_table();
    void initializer();
    ~table_manager();
};

 

#endif