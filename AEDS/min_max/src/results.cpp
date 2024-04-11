#include "results.hpp"

results::results()
{
  ofstream output = ofstream("results.txt");

  output.close();

  ofstream outpu = ofstream("data.txt");

  outpu.close();

  ofstream out = ofstream("results.csv");

  out << "Tempo de execucao, Entrada de dados, Algoritimo, Ordenacao" << endl;

  out.close();
}

void results::write_results(int methodoNumber, int size, string type, double time, string path)
{

  ofstream output = ofstream(path, ofstream::app);

  output << "MinMax: " << methodoNumber << " Array size: " << size << " type: " << type << " time: " << time << "\n";

  output.close();
  ofstream outpu = ofstream("data.txt", ofstream::app);

  outpu << time << " " << size << "\n";

  outpu.close();

  ofstream out = ofstream("results.csv", ofstream::app);

  out <<  time << ", "<< size <<", "<< methodoNumber<< ", "<< type<< endl; 

  out.close();
}