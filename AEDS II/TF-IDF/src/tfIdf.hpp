#ifndef TFIDF_HPP
#define TFIDF_HPP

#define KEYWORDSPATH "datasets/keyWords.txt"

#include <bits/stdc++.h>

using namespace std;

class TfIdf
{

public:
    unordered_map<string, vector<float>> tfRank;
    unordered_map<string, float> idfRank;
    vector<string> keyWords;
    unordered_map<string, vector<float>> wordsScore;

    TfIdf(vector<unordered_map<string, int>> wordsInDocs);

    unordered_map<string, vector<float>> tf(vector<unordered_map<string, int>> wordsInDocs);
    unordered_map<string, float> idf(vector<unordered_map<string, int>> wordsInDocs);
    unordered_map<string, vector<float>> calculateScore();
    vector<string> processKeyWords();
    string processLine(string line);
    void showScore();
};

#endif