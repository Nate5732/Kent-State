// Nathon Iadimarco
// CS3 Lab2
// 1/24/2024
// Word Count Lab (Case Insensitive)
// Implement a program that reads in a text file, counts how many times each word occurs in the file and outputs the words (and counts) in the increasing order of occurrence, i.e. the counts need to be output in sorted order: rare words first. Word is any sequence of alphanumeric characters separateed by whitespace or punctuation marks. Whitespace and punctuation marks are to be discarded. That is, the punctuation marks should not be counted either as a part of the word or as a separate word. You are free to make your program case sensitive (Hello and hello are counted as separate words) or case insensitive. File name is supplied on command line. You are to use the following classes.

#include "Header.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "More arguments needed" << endl;
        return 0;
     }
        std::ifstream textFile (argv[1]); // Opening Text File
        WordList wl;
        string line;
    
    if (!textFile.is_open()) {
        cout << "Unable to open text file." << endl;
        return 0;
        
    } else {
        while (textFile >> line) { // Inputting words character by character into "line" string
            string word;
            bool inWord = false; // Used to ensure word is an alphanumeric value and not a repeating symbol.
            for (int i = 0; i < line.size(); ++i) { // Collecting what is stored in current line of text file and inserting it into tmpChar.
                char tmpChar = line[i];
                if (isalnum(tmpChar) || isupper(tmpChar)) { // Checking if the word is alphanumeric or upper case.
                    tmpChar = char(tolower(tmpChar)); // Changing upper case to lowercase.
                    word.append(sizeof(tmpChar), tmpChar); // extending the length of the string "word" and adding the value stored in tmpChar into the "word".
                    inWord = true;
                } else if (!word.empty()) { // When tmpChar is a symbol we will add the stored word string to the list as long as it is not empty.
                        wl.addWord(word);
                        word.erase();
                        inWord = false; // Indicate no longer in a word so if next character in line is a symbol we will not add to list.
                }
            }
            if (inWord) {
                wl.addWord(word);
            }
        }
    wl.print();
    textFile.close();
    }
}

