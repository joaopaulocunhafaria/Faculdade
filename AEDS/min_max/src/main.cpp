#include <iostream> 
#include "minMax.hpp" 

using namespace std;

int main()
{
     minMax m = minMax();
     
    cout << endl << "Starting execution" << endl;
   m.manage_executions();

   
    cout << endl << "Ending execution" << endl;

    return 0;
}