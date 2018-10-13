#include <iostream>
#include <fstream>
#include <vector>
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

vector< pair <string,int> > map(vector<string> inputReaderVec){
    vector< pair <string,int> > wordPairs;
    for(int i=0; i<inputReaderVec.size(); i++){
        wordPairs.push_back(make_pair(inputReaderVec[i], 1));
    }
    return wordPairs;

}

vector< pair <string,int> > reduce(vector< pair <string,int> > wordPairs){
    vector< pair <string,int> > wordPairsReduced;
    string word;
    int count = 1;

    sort(wordPairs.begin(), wordPairs.end());
    word = wordPairs[0].first;
    
    for(int i=1; i<=wordPairs.size(); i++){
        if(word!=wordPairs[i].first){
            wordPairsReduced.push_back(make_pair(word, count));
            count = 0;
            word = wordPairs[i].first;
        }
        count++;       
    }
    return wordPairsReduced;
}

void output(vector< pair <string,int> > wordPairsReduced){
    for (int i=0; i<wordPairsReduced.size(); i++) 
    { 
        cout << "\"" << wordPairsReduced[i].first << "\""
        << " appeared " << wordPairsReduced[i].second << " times.\n"; 
    }
}