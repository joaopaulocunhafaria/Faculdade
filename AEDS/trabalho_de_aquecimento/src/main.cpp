#include <iostream>
#include "table_manager.hpp"
#define N 8
#define FILE_PATH "table.txt"

using namespace std;

int main(){
    
    table_manager m =   table_manager(N,FILE_PATH);

    m.initializer();

    cout << "Hello world";

    return 0;
}