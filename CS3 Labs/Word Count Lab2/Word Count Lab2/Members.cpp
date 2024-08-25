// Nathon Iadimarco
// Defining body of members within WordOccurrence Class and WordList Class
// CS3

#include "Header.hpp"

WordOccurrence::WordOccurrence(const string& word, int num) { // Setting private class variables to hold the values stored in the word and num variables used in WordOccurence.
    word_ = word;
    num_ = num;
}

bool WordOccurrence::matchWord(const string &word) { // Tests if words match
    if (word_ == word) {
        return true;
    } else {
        return false;
    }
}

void WordOccurrence::increment() { // Increments private member variable (num_) in WordOccurrence class
    ++num_;
}

string WordOccurrence::getWord() const { // returning word_ as a constant to ensure it will not be manipulated
    return word_;
}

int WordOccurrence::getNum() const { // returning num_ as a constant to ensure it will not be manipulated
    return num_;
}


WordList::WordList() { // Default Constructor setting size to 0 and word array to an array WordOccurrence of size 0.
    size_ = 0;
    wordArray_ = new WordOccurrence[size_];
}

WordList::WordList(const WordList& rhs) { // Copy Constructor iterates through rhs array and copies values into wordArray
    size_ = rhs.size_;
    wordArray_ = new WordOccurrence[size_];
    
    for (int i = 0; i < size_; ++i) {
        wordArray_[i] = rhs.wordArray_[i];
    }
}

WordList::~WordList() { // Destructor to deallocate memory within wordArray_.
    delete[] wordArray_;
}

WordList& WordList::operator= (WordList rhs) { // Overloading assignment operator to copy rhs values into wordArray_ and return *this.
    if (this == &rhs) {
        return *this;
    }
    
    if (wordArray_ != nullptr) {
      delete[] wordArray_;
    }
    
    size_ = rhs.size_;
    wordArray_ = new WordOccurrence[size_];
    
    for (int i = 0; i < size_; ++i) {
      wordArray_[i] = rhs.wordArray_[i];
    }
    
    return *this;
}

bool equal(const WordList& lhs, const WordList& rhs) { // Checks if lhs and rhs arrays are exactly equal. First checks for size to be equal then checks each array value for word and num equality.
    if (lhs.size_ != rhs.size_) return false;
    
    for (int i = 0; i < lhs.size_; ++i) {
        if (lhs.wordArray_[i].getWord() != rhs.wordArray_[i].getWord() ||
            lhs.wordArray_[i].getNum() != rhs.wordArray_[i].getNum()) {
            return false;
        }
    }
    return true; // Arrays are equal.
}


void WordList::addWord(const string& word) {
    
    for(int i = 0; i < size_; ++i) {
           if(wordArray_[i].matchWord(word)) { // checks if word matches any words stored in array.
               wordArray_[i].increment(); // Increments num_ count related to specific word if there was a match.
               return;
           }
       }

    WordOccurrence* tmpArray = wordArray_; // Copying wordArray values into temp array that has a size that is 1 value larger to insert new word.
    wordArray_ = new WordOccurrence[size_ + 1];
    for (int i = 0; i < size_; ++i) { // Copying values from wordArray_ into new temp array.
        wordArray_[i] = tmpArray[i];
    }
    wordArray_[size_] = word; // Adding the new word into the last value of array that was just added in when size was increased by 1.
    wordArray_[size_].increment(); // increments num_ for word count because of added word.
    delete[] tmpArray; // Deallocating tmpArray using destructor
    size_++;
}



void WordList::print() {
    
    if (size_ == 0)  {
        std::cout << "Array is empty." << std::endl;
        return;
    }
    
    for (int i = 0; i < size_; i++) { // Using nested for loop to iterate through array and count the number of word occurrences that happen.
        for (int j = i + 1; j < size_; j++) {
            if (wordArray_[i].getNum() > wordArray_[j].getNum()) { // if the line before the next line has a greater # of word occurences, a new array is made
                WordOccurrence* temp = new WordOccurrence[size_];
                temp[i] = wordArray_[i]; // new array stores current line in wordarray
                wordArray_[i] = wordArray_[j]; // wordarray stores next lines value into current line
                wordArray_[j] = temp[i]; // next lines value takes in the value from previous line that has been stored in temp array.
            }
        }
    }
    
    for (int i = 0; i < size_; ++i) {
        cout << wordArray_[i].getNum() <<": "<< wordArray_[i].getWord() << endl; // Outputting number of occurrences, then the word that occurs.
    }
}

