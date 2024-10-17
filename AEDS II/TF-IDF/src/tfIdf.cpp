#include "tfIdf.hpp"

TfIdf::TfIdf(vector<unordered_map<string, int>> wordsInDocs)
{
    this->keyWords = processKeyWords();
    this->idfRank = idf(wordsInDocs);
    this->tfRank = tf(wordsInDocs);
    this->wordsScore = calculateScore();
    showScore();
}

unordered_map<string, double> TfIdf::idf(vector<unordered_map<string, int>> wordsInDocs)
{
    unordered_map<string, double> result;

    int totalNumberOfDocuments = wordsInDocs.size();
    for (auto key : keyWords)
    {
        int numberOfDocsKeyAppers;
        for (int i = 0; i < totalNumberOfDocuments; i++)
        {
            if (wordsInDocs[i].find(key) != wordsInDocs[i].end())
            {
                numberOfDocsKeyAppers++;
            }
        }

        result[key] = log(static_cast<double>(totalNumberOfDocuments) / 1 + static_cast<double>(numberOfDocsKeyAppers));
    }

    return result;
}

unordered_map<string, vector<double>> TfIdf::tf(vector<unordered_map<string, int>> wordsInDocs)
{
    unordered_map<string, vector<double>> tfPerDoc;
    int docsQuantity = wordsInDocs.size();

    for (auto key : keyWords)
    {
        int howManyApperanceInEachDocument;
        int totalTermsInDoc;
        for (int i = 0; i < docsQuantity; i++)
        {
            totalTermsInDoc = wordsInDocs[i].size();
            howManyApperanceInEachDocument = wordsInDocs[i][key];
            double result = static_cast<double>(howManyApperanceInEachDocument) / static_cast<double>(totalTermsInDoc);
            tfPerDoc[key].push_back(result);
        }
    }

    return tfPerDoc;
}

vector<string> TfIdf::processKeyWords()
{

    vector<string> result;

    ifstream file(KEYWORDSPATH);

    string line;

    while (getline(file, line))
    {
        string keyWord = processLine(line);
        result.push_back(keyWord);
    }
    file.close();

    return result;
}

string TfIdf::processLine(string line)
{

    if (!line.empty())
    {

        transform(line.begin(), line.end(), line.begin(), [](unsigned char c)
                  {
                      return std::tolower(c); // Converte cada caractere para minúscula
                  });
        // tirar os acentos

        line.erase(remove_if(line.begin(), line.end(),
                             [](unsigned char c)
                             { return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';' || c == '"' || c == '\'' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '-' || c == '_'; }),
                   line.end());
    }

    return line;
}

unordered_map<string, vector<double>> TfIdf::calculateScore()
{

    unordered_map<string, vector<double>> score;

    for (size_t i = 0; i < keyWords.size(); i++)
    {
        string key = keyWords[i];

        vector<double> resultPerKey;

        for (size_t j = 0; j < tfRank[key].size(); j++)
        {
            resultPerKey.push_back(tfRank[key][j] * idfRank[key]);
        }

        score[key] = resultPerKey;
    }

    return score;
}

void TfIdf::showScore()
{

    for (size_t i = 0; i < keyWords.size(); i++)
    {
        string key = keyWords[i];

        int sortedIndex = findMaxIndex(wordsScore[key]);
        cout << " A palavra " << key << " aparece mais no documento " << sortedIndex +1<< endl;

        
    }
}

int TfIdf::partition(vector<double> &arr, std::vector<int> &indices, int low, int high)
{
    double pivot = arr[indices[high]];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[indices[j]] <= pivot)
        {
            i++;
            std::swap(indices[i], indices[j]);
        }
    }
    std::swap(indices[i + 1], indices[high]);
    return (i + 1);
}

void TfIdf::quickSort(vector<double> &arr, vector<int> &indices, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, indices, low, high);

        quickSort(arr, indices, low, pi - 1);
        quickSort(arr, indices, pi + 1, high);
    }
}

vector<int> TfIdf::sortByIndex(vector<double> &arr)
{
    vector<int> indices(arr.size());
    for (size_t i = 0; i < arr.size(); i++)
    {
        indices[i] = i;
    }

    cout << "Sorted array" << endl;
    quickSort(arr, indices, 0, arr.size() - 1);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }

    cout << endl;
    return indices;
}

int TfIdf::findMaxIndex(const std::vector<double> &arr)
{
    if (arr.empty())
    {
        return -1;
    }

    int indice_maior = 0;

    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[indice_maior])
        {
            indice_maior = i;
        }
    }

    return indice_maior;
}
