#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "guestMatrixMultiply.hpp"

using namespace std;

vector<string> inputReader(ifstream& file){
    vector<string> inputReaderVec;
    string element; 
    int rowNum = 0; 
    int colNum = 0; 

    while(file >> element){
        if(element == "A"){continue;}
        if(element == "B"){break;}
        if(element != ";"){
            inputReaderVec.push_back("A:" + to_string(rowNum) + ":" + to_string(colNum) + ":" + element); 
            colNum++; 
        }else if(element == ";"){
            colNum = 0; 
            rowNum++; 
        }
    }

    rowNum = 0; 
    colNum = 0;

    while(file >> element){
        if(element != ";"){
            inputReaderVec.push_back("B:" + to_string(rowNum) + ":" + to_string(colNum) + ":" + element); 
            colNum++; 
        }else if(element == ";"){
            colNum = 0; 
            rowNum++; 
        }
    }

    for(int i; i<inputReaderVec.size(); i++){
        cout << inputReaderVec[i] << endl;
    }
        
    return inputReaderVec; 
}

pair <string,int> map(string element){
    for(int i = 0; i<element.size(); )
    {

    }
    
    //return ;// returns a column 
}

pair <string,int> reduce(vector< pair <string,int> > wordPairGroup){
    // calculate final matrix spot with with values 
    //return std::pair<string,int>(wordPairGroup[0].first,wordPairGroup.size());
}

void output(vector< pair <string,int> > wordPairsReduced){

    // output final matrix 
}