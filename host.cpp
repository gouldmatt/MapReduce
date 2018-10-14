
#include <iostream> 
#include <fstream>
#include <vector>
#include <thread> 
#include <algorithm> 
#include <unordered_map> 
#include "guestWordCount.hpp"

using namespace std;

void machineMap( vector< pair <string,int> > &keyValuePair,vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum);
void machineReduce(vector< pair <string,int> > &wordPairsReduced,vector < pair<string,int> > groupedKeyValue,int machineNum);


int main(){
    thread machines[4];
    ifstream file;
    vector<string> inputReaderVec;
    vector< pair <string,int> > keyValue[4]; //(key,value)
    vector < pair<string,int> > totalKeyValue;
    vector < pair<string,int> > groupedKeyValue;
    vector< pair <string,int> > wordPairsReduced;
    unordered_multimap<string,int> keyValueHash;
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
       machines[i]=thread(machineMap,std::ref(keyValue[i]),std::ref(inputReaderVec),inputReaderVecSize,i);
    }

    // stop multithreading
    for(int i=0; i<4; i++){
        machines[i].join();
    }

    /*

    //place word pairs into hash table 
    for (int i=0; i<4; i++){
        for (int j=0; j<keyValue[i].size(); j++){
            keyValueHash.insert(pair<string,int>(keyValue[i][j].first,keyValue[i][j].second));
        }
    }    
	
    unordered_multimap <string, int> :: iterator totalIt;
    unordered_multimap <string, int> :: iterator secondIt;

    std::pair<std::unordered_multimap<string, int>::iterator,std::unordered_multimap<string, int>::iterator> r;



    // Iterate over the multimap
    for(totalIt = keyValueHash.begin(); totalIt != keyValueHash.end(); totalIt++){
        // find the number of times this key repeats 
        cout << totalIt -> first << endl; 
        r = keyValueHash.equal_range(totalIt->first);
        for(unordered_multimap<string,int>::iterator it =r.first; it != r.second; it++){
            groupedKeyValue.push_back(*it); 
        
        }
        keyValueHash.erase(totalIt->first);
    }
	
    for(int j; j< groupedKeyValue.size(); j++){
        cout << endl << groupedKeyValue[j].first << endl << endl;
    }
    */
    for (int i=0; i<4; i++){
        for (int j=0; j<keyValue[i].size(); j++){
            totalKeyValue.push_back(pair<string,int>(keyValue[i][j].first,keyValue[i][j].second));
        }
    }    


    string word;
    int count = 1;

    sort(totalKeyValue.begin(), totalKeyValue.end());
    word = totalKeyValue[0].first;
    
    for(int i=1; i<totalKeyValue.size(); i++){
        if(word!=totalKeyValue[i].first){
            // call threads
          
            word = totalKeyValue[i].first;
        }
        groupedKeyValue.push_back(pair<string,int>(totalKeyValue[i].first,totalKeyValue[i].second));
    }


    // start multithreading
    for(int i=0; i < 4; i++){ 
       //machines[i]=thread();
    }

    // stop multithreading
    for(int i=0; i<4; i++){
        //machines[i].join();
    }


    /*
    //Create key value pairs with values all 1 and keys are each word
    wordPairsReduced = reduce(totalWordPairs); 
    */

    //output 
    output(wordPairsReduced);
  

    return 0; 
}

void machineMap(vector< pair <string,int> > &keyValuePair, vector<string>& inputReaderVec,int inputReaderVecSize,int machineNum){
    for(int i=machineNum; i < inputReaderVecSize; i+=4){
        keyValuePair.push_back(pair<string,int> (map(inputReaderVec[i]))); 
    } 
}

void machineReduce(vector< pair <string,int> > &wordPairsReduced,vector < pair<string,int> > groupedKeyValue,int machineNum){

}