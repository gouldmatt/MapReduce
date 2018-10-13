
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

    // read the input file and feed it into the input reader
    file.open("./test.txt"); 
    if (!file){
        cerr << "Unable to open file";
        exit(1);
    }
    
    //Extract the words
    inputReaderVec = inputReader(file);
    file.close(); 

    wordPairs = map(inputReaderVec);

    for (int i=0; i<wordPairs.size(); i++) 
    { 
        cout << "\"" << wordPairs[i].first << "\""
        << " has value " << wordPairs[i].second << "\n"; 
    } 

    return 0; 
}