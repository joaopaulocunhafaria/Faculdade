#include "file_manager.hpp"

file_manager::file_manager(string file_path, int table_size)
{
    this->file_path = file_path;
    this->table_size = table_size;
}

file_manager::file_manager()
{
    ofstream output("geracoes.mps");
    output.close();
  
}

void file_manager::write_table(char **table, string path, int i)
{
    ofstream output(path, ofstream::app);

    if (!output)
    {
        cout << "File not found when trying to write. 404";
        return;
    }

    output << "Geracao: " << i << endl;

    for (int i = 0; i < this->table_size; i++)
    {
        for (int j = 0; j < this->table_size; j++)
        {

            output << table[i][j];
        }
        output << "\n";
    }
    output << "**********" << endl;

    output.close();
}

char **file_manager::read_table()
{
    ifstream input("datasets/input.mps");

    if (!input)
    {
        cout << "File not found when trying to read. 404";
        return 0;
    }

    char **table;

    table = new char *[this->table_size];

    for (int i = 0; i < this->table_size; i++)
    {
        table[i] = new char[this->table_size];
    }

    char aux;
    string aux1;
    getline(input, aux1);

    for (int i = 0; i < this->table_size; i++)
    {
        for (int j = 0; j < this->table_size; j++)
        {
            input.get(aux);

            if (aux != '\n')
            {
                table[i][j] = aux;
            }
            if (aux == '\n')

            {
                table[i][j] = input.get();
            }
        }
    }

    input.close();
    return table;
}
