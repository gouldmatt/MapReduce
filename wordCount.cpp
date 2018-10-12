#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool sortDescending(const pair<string,int> &a, const pair<string,int> &b);

int main(){
    string data;
    string word;
    ifstream f;
    vector<string> words;
    vector< pair <string,int> > wordCountPairs;
    int wordCount = 1; //at least 1 word if file isn't empty
    int numOfWords = 0;

    //Open file 
    f.open("./test.txt"); 
    if (!f) {
        cerr << "Unable to open the file";
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
            wordCountPairs.push_back(make_pair(word, wordCount));
            //cout << "\"" << word << "\"" << " appeared " << wordCount << " times.\n";
            wordCount = 0;
            word = words[i]; //test the next word
        }
        wordCount++;
    }

    sort(wordCountPairs.begin(), wordCountPairs.end(), sortDescending); //sort by descending counts
    
    for (int i=0; i<wordCountPairs.size(); i++) 
    { 
        cout << "\"" << wordCountPairs[i].first << "\""
        << " appeared " << wordCountPairs[i].second << " times.\n"; 
    } 

    f.close();
    return 0;
}

bool sortDescending(const pair<string,int> &a, 
              const pair<string,int> &b)
{ 
    return (a.second > b.second); 
} 