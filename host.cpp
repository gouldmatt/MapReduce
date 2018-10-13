
#include <iostream> 
#include <fstream>
#include <vector>
#include <thread> 
#include "guestWordCount.hpp"

using namespace std;

int main(){
    ifstream file;
    vector<string> inputReaderVec;
    vector< pair <string,int> > wordPairs; //(key,value)
    vector< pair <string,int> > wordPairsReduced;

    // read the input file and feed it into the input reader
    file.open("./test.txt"); 
    if (!file){
        cerr << "Unable to open file";
        exit(1);
    }
    
    //Extract the words
    inputReaderVec = inputReader(file);
    file.close(); 

    //Create key value pairs with values all 1 and keys are each word
    wordPairs = map(inputReaderVec);
    wordPairsReduced = reduce(wordPairs); 

    for (int i=0; i<wordPairsReduced.size(); i++) 
    { 
        cout << "\"" << wordPairsReduced[i].first << "\""
        << " has value " << wordPairsReduced[i].second << "\n"; 
    }

    return 0; 
}