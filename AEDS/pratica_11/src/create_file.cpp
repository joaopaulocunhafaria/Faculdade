#include "create_file.hpp"

using namespace std;

create_file::create_file() {}

void create_file::generate_data()
{
    default_random_engine generator(time(0));
    uniform_real_distribution<float> distribution(1.0, 1000000.0);

    for (int i = 0; i < 10; i++)
    {

        string number = to_string(i + 1);

        string path = "datasets/" + number + ".txt";
        ofstream output = ofstream(path);

        for (int j = 0; j < 100000; j++)
        {
            float float_number = distribution(generator);
            output << float_number << " ";
        }
        
        output.close();
    }
}
