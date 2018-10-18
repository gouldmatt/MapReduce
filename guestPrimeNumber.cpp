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
    bool prime = 0; 
    if(isPrime(stol(number))){
        prime = 1; 
    }else{
        prime = 0; 
        number = nullptr; 
    }

    return std::pair<string,int>(number, prime);
}

pair <string,int> reduce(vector< pair <string,int> > wordPairGroup){

    return std::pair<string,int>(wordPairGroup[0].first,wordPairGroup.size());
}

void output(vector< pair <string,int> > primesReduced){
    for (int i=0; i<primesReduced.size(); i++) 
    { 
        cout << "Prime Number " << primesReduced[i].first << " appeared " << primesReduced[i].second << " times\n"; 
    }
    cout << "hello";
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
}