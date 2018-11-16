/*  Author : Mohamed Abdul
 *  2018
 *  Description:
 *  Simple word counter
 */
#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

class WordCounter{
    public:
    WordCounter(string filename);
    //this return number of words
    long getNumberOfWords();
    //this returns # of characters excluding space
    long getNumberOfChars();
    //this returns # of characters including space
    long getNumberOfCharsWithSpace();
    //returns the array of words
    vector<string> getWordsArray();
    //get the whole paragraph as a string
    string getWholeString();
    //print info about the file
    void printInfo();
    //print the average size of the word
    int getAverageSizeOfWord();
private:
    long numberOfWords, numberOfChars,NumberOfCharsWithSpace;
    int averageSizeOfWord;
    vector<string> wordArray;
    string filename;
    ifstream read;
};

WordCounter::WordCounter(string filename){
    this->filename = filename;
    bool wordBegin =  false;
    char readChar;
    char lastChar = ' ';
    string word = "";
    averageSizeOfWord = 0;
    //open the file
    read.open(filename.c_str());
    //if the file doesnt exist
    if(!read.is_open())
        cout << "The " << filename << " doesnt exists." << endl;
    else{
        cout << "Processing.." << endl;
        while(read.get(readChar)){
             NumberOfCharsWithSpace++;
             if(lastChar == ' ' && readChar != ' ' && wordBegin == false){
                wordBegin = true;
            }
            if(lastChar != ' ' && readChar == ' ' && wordBegin == true){
                wordBegin = false;
                wordArray.push_back(word);
                averageSizeOfWord = averageSizeOfWord + word.length();
                word = "";
            }
            if(wordBegin){
                word = word + readChar;
                numberOfChars++;
            }
                lastChar = readChar;
        }
             
        }
    if(wordBegin){
        wordArray.push_back(word);
    }
    averageSizeOfWord = averageSizeOfWord + word.length();
    numberOfWords = wordArray.size();
    averageSizeOfWord = averageSizeOfWord / numberOfWords;
    read.close();
    
    
}

string WordCounter::getWholeString(){
    string result = "";
    for(int i = 0; i < wordArray.size(); i++){
        result = result + wordArray[i] + ' ';
    }
    return result;
}

long WordCounter::getNumberOfWords(){
    return numberOfWords;
}

long WordCounter::getNumberOfChars(){
    return numberOfChars;
}

long WordCounter::getNumberOfCharsWithSpace(){
    return  NumberOfCharsWithSpace;
}
vector<string> WordCounter::getWordsArray(){
    return wordArray;
}

int WordCounter::getAverageSizeOfWord(){
    return averageSizeOfWord;
}
void WordCounter::printInfo(){
    cout << "File Name : " << filename << endl;
    cout << "Total Number of Words : " << numberOfWords << endl;
    cout << "Average Size of a Word : " << averageSizeOfWord << endl;
    cout << "Total Number of Characters (exculding space) : " << numberOfChars << endl;
    cout << "Total Number of Characters (including space) : " << NumberOfCharsWithSpace << endl;
}
#endif
