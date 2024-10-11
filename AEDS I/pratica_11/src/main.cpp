#include <iostream>
#include "create_file.hpp"
#include "execute_process.hpp"

using namespace std;

int main()
{

    // create_file c = create_file();

    // c.generate_data();
    int process;
    cout << "How many process?" << endl;
    cin >> process;

    execute_process e = execute_process(process);

    e.run();

    return 0;
}