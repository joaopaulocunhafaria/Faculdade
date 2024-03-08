#include "file_manager.hpp"

file_manager::file_manager(string file_path, int table_size)
{
    this->file_path = file_path;
    this->table_size = table_size;
}

file_manager::file_manager(){}

void file_manager::write_table(char **table)
{
    ofstream output(this->file_path);

    if (!output)
    {
        cout << "File not found when trying to write. 404";
        return;
    }

    for (int i = 0; i < this->table_size; i++)
    {
        for (int j = 0; j < this->table_size; j++)
        {
             
            output << table[i][j];
        }
      // output << "\n";
    }

    output.close();
}

char **file_manager::read_table()
{
    ifstream input(this->file_path);

    if (!input)
    {
        cout << "File not found when trying to read. 404";
        return  0;
    }

    char **table;
    
    table = new char*[this->table_size];
    
    for (int i = 0; i < this->table_size; i++)
    {
         table[i] = new char[this->table_size];
    }

 

    for (int i = 0; i < this->table_size; i++)
    {
        for (int j = 0; j < this->table_size; j++)
        {   
            table[i][j] = input.get();
        }
    }

    input.close();
    return table;
}
 

file_manager::~file_manager(){
    
}