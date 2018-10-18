#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "guestPrimeNumber.hpp"

using namespace std;

vector<string> inputReader(ifstream& file){
    vector<string> inputReaderVec;
    string number; 
    while (file >> number){
        inputReaderVec.push_back(number);
    }
    return inputReaderVec; 
}

pair <string,int> map(string number){
    int prime = 0; 
    int numberInt = stoi(number); 
    if(isPrime(numberInt)){
        prime = 1; 
    }else{
        prime = 0; 
        number = "0"; 
    }

    return std::pair<string,int>(number, prime);
}

pair <string,int> reduce(vector< pair <string,int> > wordPairGroup){
    int frequency = 0; 
    if(wordPairGroup[0].second == 1){
        frequency = wordPairGroup.size(); 
    }else{
        frequency = 0; 
    }
    return std::pair<string,int>(wordPairGroup[0].first,frequency);
}

void output(vector< pair <string,int> > primesReduced){
    for (int i=0; i<primesReduced.size(); i++) 
    { 
        if(primesReduced[i].second > 0){
            cout << "Prime Number " << primesReduced[i].first << " appeared " << primesReduced[i].second << " times\n"; 
        }
    }
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