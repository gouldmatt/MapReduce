#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num);

int main(){
    ifstream f;
    vector<int> inputReaderVec;
    int element;       
    int count = 0;
    int temp;

    //Open file 
    f.open("./primeTest.txt"); 
    if (!f) {
        cerr << "Unable to open the file";
        exit(1);
    }

    while(f >> element){
        inputReaderVec.push_back(element);
    }
    
    for(int i=0; i<inputReaderVec.size(); i++){
        if (isPrime(inputReaderVec[i])){
            //Add to freq vect
        }
    
    }
   

   
    return 0;
}

bool isPrime(int num){
    bool prime = true;

    if(num < 2)
        prime = true;
    for (int i=2; i<num; i++)
        if (num % i == 0)
            prime = false;
    return prime ;
}
