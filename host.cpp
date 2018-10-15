
#include <iostream> 
#include <fstream>
#include <vector>
#include <thread> 
#include <algorithm> 
#include <unordered_map> 
#include "guestWordCount.hpp"

using namespace std;

void machineMap( vector< pair <string,int> > &keyValuePair,vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum);
void machineReduce(vector< pair <string,int> > &wordPairsReduced,vector < vector < pair<string,int> > > groupedKeyValue,int machineNum);


int main(){
    thread machines[4];
    ifstream file;
    vector<string> inputReaderVec;
    vector< pair <string,int> > keyValue[4]; //(key,value)
    vector< pair<string,int> > totalKeyValue;
    vector< vector < pair<string,int> > > groupedKeyValue;
    vector< pair <string,int> > keyValueReduced[4];
    vector< pair <string,int> > keyValueFinal; 

    int inputReaderVecSize = 0;
    int groupNum = 0;

    // read the input file and feed it into the input reader
    file.open("./test2.txt"); 
    if (!file){
        cerr << "Unable to open file";
        exit(1);    }
    
    //Extract the words
    inputReaderVec = inputReader(file);
    file.close(); 
    inputReaderVecSize = inputReaderVec.size(); 
  
    // start multithreading
    for(int i=0; i < 4; i++){ 
       machines[i]=thread(machineMap,std::ref(keyValue[i]),std::ref(inputReaderVec),inputReaderVecSize,i);
    }

    // stop multithreading
    for(int i=0; i<4; i++){
        machines[i].join();
    }

    // place into one total vector
    for (int i=0; i<4; i++){
        for (int j=0; j<keyValue[i].size(); j++){
            totalKeyValue.push_back(pair<string,int>(keyValue[i][j].first,keyValue[i][j].second));
        }
    }    

    sort(totalKeyValue.begin(), totalKeyValue.end());

    groupedKeyValue.push_back(vector <pair<string,int>>());
    // create groups with common keys 
    for(int i=0; i<totalKeyValue.size(); i++){
        groupedKeyValue[groupNum].push_back(pair<string,int>(totalKeyValue[i].first,totalKeyValue[i].second));
        if((totalKeyValue[i] != totalKeyValue[i+1]) || i == totalKeyValue.size()-1 ){
            groupNum++; 
            if(i != totalKeyValue.size()-1){
                groupedKeyValue.push_back(vector <pair<string,int>>());
            }
        }
    }
    
    // start multithreading
    for(int i=0; i < 4; i++){ 
       machines[i]=thread(machineReduce,std::ref(keyValueReduced[i]),groupedKeyValue,i);
    }

    // stop multithreading
    for(int i=0; i<4; i++){
        machines[i].join();
    }
    
    
    // place into one total final vector 
    for (int i=0; i<4; i++){
        for (int j=0; j<keyValueReduced[i].size(); j++){
            keyValueFinal.push_back(pair<string,int>(keyValueReduced[i][j].first,keyValueReduced[i][j].second));
        }
    }    
    

    /*
    //Create key value pairs with values all 1 and keys are each word
    wordPairsReduced = reduce(totalWordPairs); 
    */

    //output 
    output(keyValueFinal);
  

    return 0; 
}

void machineMap(vector< pair <string,int> > &keyValuePair, vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum){
    for(int i=machineNum; i < inputReaderVecSize; i+=4){
        keyValuePair.push_back(pair<string,int> (map(inputReaderVec[i]))); 
    } 
}

void machineReduce(vector< pair <string,int> > &keyValueReduced,vector < vector < pair<string,int> > > groupedKeyValue,int machineNum){
      for(int i=machineNum; i < groupedKeyValue.size(); i+=4){
        keyValueReduced.push_back(pair<string,int> (reduce(groupedKeyValue[i]))); 
    } 
}