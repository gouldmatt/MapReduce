#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "guestWordCount.hpp"

using namespace std;

vector<string> inputReader(ifstream& file){
    vector<string> inputReaderVec;
    string word; 
    while (file >> word){
        inputReaderVec.push_back(word);
    }
    return inputReaderVec; 
}

pair <string,int> map(string word){
    return std::pair<string,int>(word, 1);
}

pair <string,int> reduce(vector< pair <string,int> > wordPairGroup){
    return std::pair<string,int>(wordPairGroup[0].first,wordPairGroup.size());
}

void output(vector< pair <string,int> > wordPairsReduced){
    for (int i=0; i<wordPairsReduced.size(); i++) 
    { 
        cout << "\"" << wordPairsReduced[i].first << "\""
        << " appeared " << wordPairsReduced[i].second << " times.\n"; 
    }
}