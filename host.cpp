
#include <iostream> 
#include <fstream>
#include <vector>
#include <thread> 
#include "guestWordCount.hpp"

using namespace std;

int main(){
    ifstream file;
    vector<string> inputReaderVec;

    // read the input file and feed it into the input reader
    file.open("./test.txt"); 
    if (!file){
        cerr << "Unable to open file";
        exit(1);
    }
    
    //Extract the words
    inputReaderVec = inputReader(file);
    file.close(); 
    return 0; 
}