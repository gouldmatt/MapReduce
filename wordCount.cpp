#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    string data;
    string word;
    ifstream f;
    vector<string> words;
    int wordCount = 1; //at least 1 word if file isn't empty
    int numOfWords = 0;

    //Open file 
    f.open("./test.txt"); 
    if (!f) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }

    //Extract the words
    while (f >> word){
        words.push_back(word);
    }

    sort(words.begin(), words.end()); //puts words in alphabetical order

    numOfWords = words.size();
    if(numOfWords==0){
        cout << "No words\n";
        return 1;
    }

    word = words[0]; //the first word
    for(int i=1; i<=numOfWords; i++){
        
        if(word!=words[i]){
            //Previous word isn't the same as the next in vector
            cout << "\"" << word << "\"" << " appeared " << wordCount << " times.\n";
            wordCount = 0;
            word = words[i]; //test the next word
        }
        wordCount++;
    }

    /* //Print words
    for (auto&& word : words){
        cout << word << '\n';
    } */

    f.close();
    return 0;
}