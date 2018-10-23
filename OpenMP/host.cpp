#include <iostream> 
#include <fstream>
#include <vector>
#include <omp.h>
#include <algorithm> 
#include "guestWordCount.hpp"

using namespace std;

void machineMap( vector< pair <string,int> > &keyValuePair,vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum,int numberOfMachines);
void machineReduce(vector< pair <string,int> > &wordPairsReduced,vector < vector < pair<string,int> > > groupedKeyValue,int machineNum,int numberOfMachines);


int main(){
   
    int numberOfMachines = 2; 
    ifstream file;
    vector<string> inputReaderVec;
    vector< pair <string,int> > keyValue[numberOfMachines]; //(key,value)
    vector< pair<string,int> > totalKeyValue;
    vector< vector < pair<string,int> > > groupedKeyValue;
    vector< pair <string,int> > keyValueReduced[numberOfMachines];
    vector< pair <string,int> > keyValueFinal; 

    int inputReaderVecSize = 0;
    int groupNum = 0;

    // read the input file and feed it into the input reader
    file.open("./test.txt"); 
    if (!file){
        cerr << "Unable to open file";
        exit(1);    
    }
    
    //Extract the words
    inputReaderVec = inputReader(file);
    file.close(); 
    
    inputReaderVecSize = inputReaderVec.size(); 
  
    // start multithreading
    #pragma omp parallel for num_threads(3)
    for(int i=0; i<numberOfMachines; i++){ 
       machineMap(keyValue[i],inputReaderVec,inputReaderVecSize,i,numberOfMachines);
    }

    inputReaderVec.clear(); 

    // place into one total vector
    for (int i=0; i<numberOfMachines; i++){
        for (int j=0; j<keyValue[i].size(); j++){
            totalKeyValue.push_back(pair<string,int>(keyValue[i][j].first,keyValue[i][j].second));
        }
        keyValue[i].clear(); 
    }    

    sort(totalKeyValue.begin(), totalKeyValue.end());

    groupedKeyValue.push_back(vector <pair<string,int> >());
    // create groups with common keys 
    for(int i=0; i<totalKeyValue.size(); i++){
        groupedKeyValue[groupNum].push_back(pair<string,int>(totalKeyValue[i].first,totalKeyValue[i].second));
        if((totalKeyValue[i] != totalKeyValue[i+1]) || i == totalKeyValue.size()-1 ){
            groupNum++; 
            if(i != totalKeyValue.size()-1){
                groupedKeyValue.push_back(vector <pair<string,int> >());
            }
        }
    }

    totalKeyValue.clear(); 
    
    // start multithreading
    #pragma omp parallel for num_threads(3)
    for(int i=0; i<numberOfMachines; i++){ 
       machineReduce(keyValueReduced[i],groupedKeyValue,i,numberOfMachines);
    }

    groupedKeyValue.clear(); 
    
    // place into one total final vector 
    for (int i=0; i<numberOfMachines; i++){
        for (int j=0; j<keyValueReduced[i].size(); j++){
            keyValueFinal.push_back(pair<string,int>(keyValueReduced[i][j].first,keyValueReduced[i][j].second));
        }
        keyValueReduced[i].clear(); 
    }    

    //output 
    output(keyValueFinal);
    
    return 0; 
}

void machineMap(vector< pair <string,int> > &keyValuePair, vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum,int numberOfMachines){
    if(machineNum < inputReaderVecSize){
        for(int i=machineNum; i < inputReaderVecSize; i+=numberOfMachines){
            keyValuePair.push_back(pair<string,int> (map(inputReaderVec[i]))); 
        }
    }
}

void machineReduce(vector< pair <string,int> > &keyValueReduced,vector < vector < pair<string,int> > > groupedKeyValue,int machineNum, int numberOfMachines){
    if(machineNum < groupedKeyValue.size()){
        for(int i=machineNum; i < groupedKeyValue.size(); i+=numberOfMachines){
            keyValueReduced.push_back(pair<string,int> (reduce(groupedKeyValue[i]))); 
        } 
    }
}