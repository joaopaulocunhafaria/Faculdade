#include "results.hpp"

results::results()
{
  ofstream output = ofstream("results.txt");

  output.close();
    ofstream outpu = ofstream("data.txt");

  outpu.close();
}

void results::write_results(int methodoNumber, int size, string type, double time, string path)
{

  ofstream output = ofstream(path, ofstream::app);

  output << "MinMax: " << methodoNumber << " Array size: " << size << " type: " << type << " time: " << time << "\n";

  output.close();
  ofstream outpu = ofstream("data.txt", ofstream::app);


  outpu << time<<" "<<size<<"\n";

  outpu.close();
}