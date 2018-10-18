#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num);

int main(){
    ifstream f;
    vector<int> inputReaderVec;
    vector< pair <int,int> > primeFreq; // first int is the prime num, second int is its freq
    int element;       
    int count = 1;
    int num;

    //Open file 
    f.open("./primeTest.txt"); 
    if (!f) {
        cerr << "Unable to open the file";
        exit(1);
    }

    while(f >> element){
        inputReaderVec.push_back(element);
    }
    
    f.close();

    sort(inputReaderVec.begin(), inputReaderVec.end());

    num = inputReaderVec[0]; //the first word
    for(int i=1; i<=inputReaderVec.size(); i++){
        if(isPrime(inputReaderVec[i])){
            if(num!=inputReaderVec[i]){
                //Previous num isn't the same as the next in vector
                primeFreq.push_back(make_pair(num, count));
                //cout << "\"" << word << "\"" << " appeared " << wordCount << " times.\n";
                count = 0;
                num = inputReaderVec[i]; //test the next word
            }
            count++;
        }
    }

    for (int i=0; i<primeFreq.size(); i++) 
    { 
        cout << "\"" << primeFreq[i].first << "\""
        << " appeared " << primeFreq[i].second << " times.\n"; 
    } 
   
    return 0;
}

bool isPrime(int num){
    bool prime = true;

    if(num < 2)
        prime = true;
    for (int i=2; i<num; i++){
        if (num % i == 0){
            prime = false;
        }     
    }
        
    return prime ;
}
