#include "execute_process.hpp"

execute_process::execute_process(int quantity)
{
    this->quantity = quantity;
    ofstream out = ofstream("datasets/output.txt");
    out.close();
}

execute_process::~execute_process() {}

float execute_process::result_per_file(string path)
{

    ifstream in = ifstream(path);

    if (!in.is_open())
    {
        cerr << "Erro ao abrir o arquivo: " << path << endl;
        return 0.0f;
    }

    string line;
    float aux = 0;
    float num;

    while (getline(in, line))
    {
        stringstream ss(line);

        while (ss >> num)
        {
            aux += num;
        }
    }

    in.close();
    return sqrt(aux);
}

float execute_process::result_per_process(string process_path)
{

    ifstream in = ifstream(process_path);

    if (!in.is_open())
    {
        std::cerr << "Failed to open file: " << process_path << std::endl;
        return -1.0;
    }

    string line;
    vector<float> resultPerProcess;

    while (getline(in, line))
    {

        stringstream ss(line);
        int num;

        float resultPerLine = 0;

        while (ss >> num)
        {
            string filePath = "";
            filePath = "datasets/" + to_string(num) + ".txt";
            float aux = result_per_file(filePath);
            resultPerLine += aux;
        }

        resultPerProcess.push_back(resultPerLine);
    }

    float finalResult;

    for (int i = 0; i < static_cast<int>(resultPerProcess.size()); i++)
    {
        finalResult += resultPerProcess[i];
    }

    in.close();
    return finalResult;
}

void execute_process::run()
{
    ofstream out("datasets/output.txt");
    auto start = std::chrono::high_resolution_clock::now();

    if (!out.is_open())
    {
        cerr << "Erro ao abrir o arquivo de saída: datasets/output.txt" << endl;
        return;
    }

    for (int i = 0; i < this->quantity; i++)
    {
        string filePath = "datasets/P" + to_string(i + 1) + ".txt";
        float resultado = result_per_process(filePath);
        out << "P" << (i + 1) << " = " << resultado << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    out << "Tempo de execucao: " << duration.count();
    out.close();
    cout << "Resultados escritos em datasets/output.txt" << endl;
}