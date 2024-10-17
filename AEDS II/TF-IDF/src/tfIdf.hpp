#ifndef TFIDF_HPP
#define TFIDF_HPP

#define KEYWORDSPATH "datasets/keyWords.txt"

#include <bits/stdc++.h>

using namespace std;

class TfIdf
{

public:
    unordered_map<string, vector<double>> tfRank;
    unordered_map<string, double> idfRank;
    vector<string> keyWords;
    unordered_map<string, vector<double>> wordsScore;

    TfIdf(vector<unordered_map<string, int>> wordsInDocs);

    unordered_map<string, vector<double>> tf(vector<unordered_map<string, int>> wordsInDocs);
    unordered_map<string, double> idf(vector<unordered_map<string, int>> wordsInDocs);
    unordered_map<string, vector<double>> calculateScore();
    vector<string> processKeyWords();
    string processLine(string line);

    void rankScore(vector<double> score);

    int partition(std::vector<double> &arr, std::vector<int> &indices, int low, int high);
    void quickSort(std::vector<double> &arr, std::vector<int> &indices, int low, int high);
    vector<int> sortByIndex(std::vector<double> &arr);
    int findMaxIndex(const std::vector<double> &arr);

    void showScore();
};

#endif