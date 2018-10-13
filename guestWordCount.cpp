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

void reduce(){

}

void output(){
    
}
