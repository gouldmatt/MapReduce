#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "guestMatrixMultiply.hpp"

using namespace std;

vector<string> inputReader(ifstream& file){
    vector<string> inputReaderVec;
    string line; 
    string temp; 
    string temp2; 

    while (!file.eof()){
        cout << "test"; 
        getline(file,line); 
        for(int i = 0; i<line.size(); i++){
            temp = string(1,line[i]); 
            if(temp != "[" || temp != "]" || temp != ","){
                temp2 += temp; 
            } 
            if (temp == ";"){ break; }
        }

    }
    cout << temp2; 
    // return matrix:row:col:value 

    return inputReaderVec; 
}

pair <string,int> map(string matrix){
    
    // map each matrix column and row vector to group for calc of spot in final matrix 
    //return std::pair<string,int>(word, 1);
}

pair <string,int> reduce(vector< pair <string,int> > wordPairGroup){
    // calculate final matrix spot with with values 
    //return std::pair<string,int>(wordPairGroup[0].first,wordPairGroup.size());
}

void output(vector< pair <string,int> > wordPairsReduced){

    // output final matrix 
}