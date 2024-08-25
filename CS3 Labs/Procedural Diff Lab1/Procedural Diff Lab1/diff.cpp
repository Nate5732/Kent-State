// Nathon Iadimarco
// CS3 Lab1
// 1/18/2024
// Procedural Diff Lab 1
// Implement a program that compares two text files character-by-character. The program should output the line numbers that contain different characters and the place where the two lines start to differ. The difference is denoted by ^ (caret) character. If both files are identical, the program should output nothing.

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    cout << "Procedural Diff: " << argv[1] << " " << argv[2] << endl << endl;
    if (argc < 3) {
        cout << "Need more arguments." << endl;
    }
    std::ifstream file1 (argv[1]);
    std::ifstream file2 (argv[2]);
    string first, second; // Used to store lines of text from file1 and file2.
    int lineNumber = 1; // Starting on first line of text.
    int spaces; // Used to count number of spaces to input before the caret.
    
    if (!file1.is_open() || !file2.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return 0;
        
    } else {
        while (!file1.eof() || !file2.eof()){
            if(file1.eof()) {
                first = "";
            }
            
            if(file2.eof()) {
                second = "";
            }
            
            getline(file1, first);
            getline(file2, second);
    
            if (first != second) {
                cout << argv[1] << ": " << lineNumber << ": " << first << endl;
                cout << argv[2] << ": " << lineNumber << ": " << second << endl;
                
                // Collecting value for number of spaces required for file names, converting line number into a string to add spaces for digit length, and 4 spaces for 2 colons and 2 spaces. (int) which is a cast, solves implicit conversion warning.
                spaces = (int)(strlen(argv[1]) + (std::to_string(lineNumber).length()) + 4);
                // Printing that exact number of spaces.
                for(int i = 0; i < spaces; ++i){
                    cout << " ";
                }
                // Printing spaces for matching characters in files
                for(int i = 0; first[i] == second[i]; ++i){
                    cout << " ";
                }
                cout << "^" << endl;
            }
            // Increase Line Number Count to iterate and compare line 2 and after until eof.
            ++lineNumber;
        }
    }
    return 0;
}

