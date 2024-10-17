#include "processBooks.hpp"

ProcessBooks::ProcessBooks(int booksQuantity)
{

    this->booksQuantity = booksQuantity;

    this->stopWords = processStopWords();

    this->wordsInDocument = processWords();

    TfIdf tfIdf = TfIdf(wordsInDocument);

};

unordered_set<string> ProcessBooks::processStopWords()
{

    ifstream file(STOPWORDSPATH);

    unordered_set<string> stopWords;
    string line;

    while (getline(file, line))
    {
        stopWords.insert(line);
    }

    file.close();
     return stopWords;
}

vector<string> ProcessBooks::processLine(string line)
{

    vector<string> result;

    if (!line.empty())
    {
        vector<string> lineWords = splitString(line);

        for (size_t i = 0; i < lineWords.size(); i++)
        {
            string word = lineWords.at(i);

            if (stopWords.find(word) == stopWords.end() && !word.empty() && word != "")
            {
                if (word.begin() != word.end())
                {
                    transform(word.begin(), word.end(), word.begin(), [](unsigned char c)
                              {
                                  return std::tolower(c); // Converte cada caractere para minúscula
                              });
                    // tirar os acentos

                    word.erase(remove_if(word.begin(), word.end(),
                                         [](unsigned char c)
                                         { return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';' || c == '"' || c == '\'' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '-' || c == '_'; }),
                               word.end());
                     result.push_back(word);
                }
            }
        }
    }

    return result;
}

vector<string> ProcessBooks::splitString(string str)
{
    vector<string> result;
    stringstream ss(str);
    string token;
    char delimiter = ' ';

    while (std::getline(ss, token, delimiter))
    {
        result.push_back(token);
    }

    return result;
}

vector<unordered_map<string, int>> ProcessBooks::processWords()
{

    vector<unordered_map<string, int>> result;

    for (int i = 0; i < booksQuantity; i++)
    {
        string filePath = BOOKSPATH + to_string(i + 1) + ".txt";
         
        ifstream file(filePath);
        string line;
        unordered_map<string, int> wordCounter;
        while (getline(file, line))
        {
            if (!line.empty())
            {
                vector<string> lineWords = processLine(line);

                for (auto word : lineWords)
                {
                    wordCounter[word]++;
                }
            }
        }
        result.push_back(wordCounter);
        file.close();
    }

    return result;
}