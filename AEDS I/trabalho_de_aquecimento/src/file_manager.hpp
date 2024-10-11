#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class file_manager
{
private:
    
    int table_size;
    string file_path;
     
public:
    file_manager();
    file_manager(string file_path, int table_size);
    void  write_table( char **table,string path, int i );    
    char ** read_table();
    
};
 

 #endif