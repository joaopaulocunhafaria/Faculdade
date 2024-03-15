#include <iostream>
#include "table_manager.hpp"

#define FILE_PATH "datasets/input.mps"

using namespace std;

int main()
{

    int executions = 0;
    cout << endl << "Starting execution" << endl;

    cout << "Type the amount of executions: " << endl;
    cin >> executions;

    table_manager m = table_manager(FILE_PATH, executions);

    m.initializer();

    cout << endl << "Ending execution" << endl;

    return 0;
}