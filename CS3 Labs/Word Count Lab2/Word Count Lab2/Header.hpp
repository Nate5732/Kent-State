//
//  Header.hpp
//  Word Count Lab2
//
//  Created by Nathon Iadimarco on 1/24/2024
//


#ifndef Header_hpp
#define Header_hpp

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::string;
using std::endl;

class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const;
    int getNum() const;

private:
    string word_;
    int num_;
};

class WordList{
public:
    
    WordList            (); // Default Constructor
    WordList            (const WordList&); // Copy Constructor
    ~WordList           (); // Destructor
    WordList& operator= (WordList); // Overloaded Assignment
    
    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    void addWord(const string &); //meant to add a word to the dynamically allocated array in the private
    void print();
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};

#endif

