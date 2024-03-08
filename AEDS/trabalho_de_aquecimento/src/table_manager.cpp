#include "table_manager.hpp"

table_manager::table_manager(int table_size, string  file_path)
{
    this->table_size = table_size;
    this->file_path = file_path;
    this->fileManager= file_manager(this->file_path,this->table_size );
    
}

char **table_manager::create_table()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    char **table;

    table = new char *[this->table_size];

    for (int i = 0; i < this->table_size; i++)
    {
        table[i] = new char[this->table_size];
    }

    int aux = 0;
    string aux2;

    for (int i = 0; i < this->table_size; i++)
    {
        for (int j = 0; j < this->table_size; j++)
        {
            aux = dis(gen);
            aux2 = to_string(aux);

            table[i][j] = aux2[0];
           
        }
        
    }
    
    fileManager.write_table(table);
    return table;
}

void table_manager::print_table()
{
    for (int i = 0; i < this->table_size; i++)
    {
        for (int j = 0; j < this->table_size; j++)
        {
            cout << this->table[i][j];
        }

        cout << "\n";
    }
}


void table_manager::next_table(){
    
}

void table_manager::initializer()
{  
    this->table =  create_table();
    fileManager.write_table(this->table);
    this->table = fileManager.read_table();
    print_table();
}

table_manager::~table_manager()
{
    for (int i = 0; i < this->table_size; i++)
    {
        delete[] this->table[i];
    }

    delete table;
}