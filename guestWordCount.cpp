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

void map(){

}

void reduce(){

}

void output(){
    
}
