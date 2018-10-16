#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "guestMatrixMultiply.hpp"

using namespace std;

vector<string> inputReader(ifstream& file){
    vector<string> inputReaderVec;
    string matrix; 
    while (file >> matrix){
        while((matrix.back()) != ']'){file >> matrix;} 
        inputReaderVec.push_back(matrix);
        
        file >> matrix; 

        while((matrix.back()) != ']'){file >> matrix;} 
        inputReaderVec.push_back(matrix);
        break; 
    }
    cout << inputReaderVec[0] << endl; 
    cout << inputReaderVec[1] << endl; 
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