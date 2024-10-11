#include "tfIdf.hpp"

TfIdf::TfIdf(vector<unordered_map<string, int>> wordsInDocs)
{
    this->keyWords = processKeyWords();
    this->idfRank = idf(wordsInDocs);
    this->tfRank = tf(wordsInDocs);
    this->wordsScore = calculateScore();
    showScore();
}

unordered_map<string, float> TfIdf::idf(vector<unordered_map<string, int>> wordsInDocs)
{
    unordered_map<string, float> result;

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

        result[key] = log(totalNumberOfDocuments / numberOfDocsKeyAppers);
    }

    return result;
}

unordered_map<string, vector<float>> TfIdf::tf(vector<unordered_map<string, int>> wordsInDocs)
{
    unordered_map<string, vector<float>> tfPerDoc;
    int docsQuantity = wordsInDocs.size();

    for (auto key : keyWords)
    {
        int howManyApperanceInEachDocument;
        int totalTermsInDoc;
        for (int i = 0; i < docsQuantity; i++)
        {
            totalTermsInDoc = wordsInDocs[i].size();
            howManyApperanceInEachDocument = wordsInDocs[i][key];
            tfPerDoc[key].push_back(howManyApperanceInEachDocument / totalTermsInDoc);
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
        cout << line << endl;
    }

    return line;
}

unordered_map<string, vector<float>> TfIdf::calculateScore()
{

    unordered_map<string, vector<float>> score;

    for (size_t i = 0; i < keyWords.size(); i++)
    {
        string key = keyWords[i];

        vector<float> resultPerKey;

        for (size_t j = 0; j < tfRank[key].size(); j++)
        {
            resultPerKey.push_back(tfRank[key][i] * idfRank[key]);
        }

        score[key] = resultPerKey;
    }

    return score;
}

void TfIdf::showScore()
{

    for (size_t i  = 0; i < keyWords.size(); i++)
    {
        string key = keyWords[i];

        cout << " A palavra " << key << " aparece: " << endl;
        for (size_t j = 0; j < wordsScore.size(); j++)
        {
            cout << wordsScore[key][i] << " vezes no doc " << i << endl;
        }
    }
}