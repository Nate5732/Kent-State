// Nathon Iadimarco Lab part 1
// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// 9/10/2018

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <map>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;
using std::map;

class Student{
public:
   Student(string firstName, string lastName):
      firstName_(firstName), lastName_(lastName) {}

   // move constructor, not really needed, generated automatically
   Student(Student && org) noexcept:
      firstName_(move(org.firstName_)),
      lastName_(move(org.lastName_))
   {}
  
   // force generation of default copy constructor
   Student(const Student & org) = default;
   
  string print() const {return firstName_ + ' ' + lastName_;}

    // needed for unique() and for remove()
   friend bool operator== (Student left, Student right){
      return left.lastName_ == right.lastName_ &&
         left.firstName_ == right.firstName_;
   }

   // needed for sort()
   friend bool operator< (Student left, Student right){
      return left.lastName_ < right.lastName_ ||
         (left.lastName_ == right.lastName_ &&
          left.firstName_ < right.firstName_);
   }
private:
   string firstName_;
   string lastName_;
};




// reading a list from a fileName
void readRoster(map<Student, list<string>>& roster, string fileName);
// printing a list out
void printRoster(const map <Student , list<string>> roster);

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0]
      << " list of courses, dropouts last" << endl; exit(1);}

   // map of courses of students
    map<Student, list<string>> roster;
   for(int i=1; i < argc; ++i) {
       readRoster(roster, argv[i]); // Reads in the files.
   }
    printRoster(roster); // Prints roster
}

void readRoster(map<Student, list<string>>& roster, string fileName){
    ifstream course(fileName); // Creating file stream
    string courseName = fileName; // Setting filename to be a string
    courseName.erase(courseName.end() - 4, courseName.end()); // removing the .txt part of the name by erasing from the . to the t in the string.
    string first, last; // Strings to hold first and last names of student
    list<string> courses; // List that will store courses
    courses.push_back(courseName); // Pushing name of course into list
    while (course >> first >> last) {
        bool check = false; // Checks if student has been located
        for (auto& name : roster) {
            if (name.first == Student(first, last)) { // If student is on record
                check = true; // The check bool is true
                name.second.push_back(courseName); // Add course name with respective student
                break;
            }
            if (courseName == "dropouts") { // If the course is dropouts
                roster.erase(Student(first, last)); // Erase the student entirely
                check = true; // Continue on
                break;
            }
        }
        if (check == false) { // If student has not been located yet
            roster.emplace(Student(first, last), courses); // Add first name, last name, and courses to the map.
        }
    }
}

// printing a list out
void printRoster(const map<Student, list<string>> roster){
    cout << "First and Last: Courses enrolled" << endl;
    cout << "--------------------------------" << endl;
    
    
    for(const auto& course : roster) {
        cout << course.first.print() << ": "; // Printing out student name.
        for(const auto& courseName : course.second) {
            cout << courseName << " "; // Printing out courses attached to specific name.
        }
        cout << endl;
    }
}




