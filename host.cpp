
#include <iostream> 
#include <fstream>
#include <vector>
#include <thread> 
#include "guestWordCount.hpp"

using namespace std;

void machineMap( vector< pair <string,int> > &keyValuePair,vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum);
void test(int i);

int main(){
    thread machines[4];
    ifstream file;
    vector<string> inputReaderVec;
    vector< pair <string,int> > wordPairs[4]; //(key,value)
    vector< pair <string,int> > totalWordPairs;
    vector< pair <string,int> > wordPairsReduced;
    int inputReaderVecSize = 0;

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
       machines[i]=thread(machineMap,std::ref(wordPairs[i]),std::ref(inputReaderVec),inputReaderVecSize,i);
    }

    // stop multithreading
    for(int i=0; i<4; i++){
        machines[i].join();
    }

    //collect word pairs into one vector
    for (int i=0; i<4; i++){
        totalWordPairs.insert(totalWordPairs.end(), wordPairs[i].begin(), wordPairs[i].end());
    }

    //Create key value pairs with values all 1 and keys are each word
    wordPairsReduced = reduce(totalWordPairs); 
    output(wordPairsReduced);
  

    return 0; 
}

void machineMap(vector< pair <string,int> > &keyValuePair, vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum){
    for(int i=machineNum; i < inputReaderVecSize; i+=4){
        keyValuePair.push_back(pair<string,int> (map(inputReaderVec[i]))); 
    } 
}