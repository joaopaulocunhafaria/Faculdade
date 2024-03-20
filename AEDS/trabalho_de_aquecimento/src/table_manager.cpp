#include "table_manager.hpp"

table_manager::table_manager(string file_path, int executions)
{
    ifstream input("datasets/input.mps");

    string size;
    getline(input, size);
    input.close();

    this->file_path = file_path;
    this->table_size = stoi(size);
    this->executions = executions;
    this->fileManager = file_manager(this->file_path, this->table_size);
    this->table = fileManager.read_table();
    this->table_aux = this->table;
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

    this->table_aux = table;
    return table;
}
 

void table_manager::next_table()
{

    for (int i = 0; i < this->table_size; i++)
    {
        for (int j = 0; j < this->table_size; j++)
        {
            table[i][j] == '0' ? dead(i, j) : alive(i, j);
        }
    }
    table = table_aux;
}

void table_manager::alive(int i, int j)
{

    int neighbors = count_neighbors(i, j);

    neighbors < 2 ? table_aux[i][j] = '0' : (neighbors > 3 ? table_aux[i][j] = '0' : table_aux[i][j] = table[i][j]);
}

void table_manager::dead(int i, int j)
{
    int neighbors = count_neighbors(i, j);

    if (neighbors == 3)
    {
        table_aux[i][j] = '1';
    }
    else
    {
        table_aux[i][j] = '0';
    }
}

bool table_manager::out_of_range(int i, int j)
{
    if (i < 0 || i > table_size - 1)
    {
        return true;
    }
    if (j < 0 || j > table_size - 1)
    {
        return true;
    }

    return false;
}

int table_manager::count_neighbors(int i, int j)
{
    int neighbors = 0;

    if (!out_of_range(i - 1, j))
    {

        if (this->table[i - 1][j] == '1')
        {
            neighbors++;
        }
    }
    if (!out_of_range(i + 1, j))
    {
        if (this->table[i + 1][j] == '1')
        {
            neighbors++;
        }
    }

    if (!out_of_range(i, j - 1))
    {
        if (this->table[i][j - 1] == '1')
        {
            neighbors++;
        }
    }

    if (!out_of_range(i, j + 1))
    {
        if (this->table[i][j + 1] == '1')
        {
            neighbors++;
        }
    }

    if (!out_of_range(i - 1, j - 1))
    {
        if (this->table[i - 1][j - 1] == '1')
        {
            neighbors++;
        }
    }

    if (!out_of_range(i + 1, j - 1))
    {
        if (this->table[i + 1][j - 1] == '1')
        {
            neighbors++;
        }
    }

    if (!out_of_range(i - 1, j + 1))
    {
        if (this->table[i - 1][j + 1] == '1')
        {
            neighbors++;
        }
    }

    if (!out_of_range(i + 1, j + 1))
    {
        if (this->table[i + 1][j + 1] == '1')
        {
            neighbors++;
        }
    }

    return neighbors;
}

void table_manager::initializer()
{
    for (int i = 0; i < executions + 1; i++)
    {
        fileManager.write_table(this->table, "geracoes.mps", i);

        next_table();
    }
    
    free_memory();
}
        
void table_manager::free_memory()
{
    for (int i = 0; i < this->table_size; i++)
    {

        delete[] this->table[i];
    }

    delete[] this->table;
}
 