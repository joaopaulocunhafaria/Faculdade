#include "results.hpp"

results::results()
{
    ofstream output = ofstream("results.txt");

    output.close();
}

void results::write_results(int methodoNumber,int size, string type,int time)
{

    ofstream output = ofstream("results.txt", ofstream::app);
    
      output << "MinMax: "<<methodoNumber <<"Array size: "<< size <<" type: "<<type<<" time: "<< time<<"\n";


     
    output.close();
}