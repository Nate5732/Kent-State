// Nathon Iadimarco Lab5R part 2
// vector and list algorithms
// Mikhail Nesterenko
// 3/11/2014

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <set>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::set;

class Student {
public:
    Student(string firstName, string lastName) :
        firstName_(firstName), lastName_(lastName) {}

    // move constructor, not really needed, generated automatically
    Student(Student && org) :
        firstName_(move(org.firstName_)),
        lastName_(move(org.lastName_))
    {}

    // force generation of default copy constructor
    Student(const Student& org) = default;

    string print() const { return firstName_ + ' ' + lastName_; }

    // needed for unique() and for remove()
    friend bool operator== (Student left, Student right) {
        return left.lastName_ == right.lastName_ &&
            left.firstName_ == right.firstName_;
    }

    // needed for sort()
    friend bool operator< (Student left, Student right) {
        return left.lastName_ < right.lastName_ ||
            (left.lastName_ == right.lastName_ &&
                left.firstName_ < right.firstName_);
    }
private:
    string firstName_;
    string lastName_;
};

// reading a list from a fileName
void readRoster(set<Student>& roster, string fileName);
// printing a list out
void printRoster(const set<Student>& roster);

int main(int argc, char* argv[]) {

    if (argc <= 1) {
        cout << "usage: " << argv[0]
            << " list of courses, dropouts last" << endl; exit(1);
    }

    // Roster Set
    set<Student> roster;

    for (int i = 1; i < argc - 1; ++i) {
        readRoster(roster, argv[i]); // Reads in file contents
    }
    
    // Reading in the dropouts
    set<Student> dropouts;
    readRoster(dropouts, argv[argc - 1]);
    
    // Removing dropouts
    for (const auto& str : dropouts) {
        roster.erase(str);
    }
    
    printRoster(roster); // Printing roster
}

void readRoster(set<Student>& roster, string fileName) {
    ifstream course(fileName); // Creating file stream
    string first, last; // Making a string for first and last name
    while (course >> first >> last) {
        bool check = false; // Checks if student name is in the file
        for (auto& student : roster) {
            if (student == Student(first, last)) { // If a student is found
                check = true; // Check is true
                break;
            }
        }
        
        if (!check) { // If check is still false
            roster.insert(Student(first, last)); // Add in the student
        }
    }
    course.close();
}

// printing a list out
void printRoster(const set<Student>& roster) {
    cout << "Currently Enrolled Students" << endl;
    cout << "---------------------------" << endl;
    for (const auto& student : roster)
        cout << student.print() << endl;
}



