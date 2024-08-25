// Nathon Iadimarco Lab4
// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// 9/10/2018

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;


class Student{
public:
   Student(string firstName, string lastName, string className):
    firstName_(firstName), lastName_(lastName) {students_.push_back(className);}
 
  
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
    
    string get_firstName_() const { return firstName_;} // returning students first name
    string get_lastName_() const { return lastName_;} // returning students last name
    
    // Printing all names of students
    void printList() {
        for (auto roster : students_) {
            cout << roster << " ";
        }
    }
    // Adds course to the list.
    void addCourse(const string filename) {
        students_.push_back(filename);
    }
    
private:
    string firstName_; // First name
    string lastName_; // Last name
    list<string> students_; // List of students
};




// reading a list from a fileName
void readRoster(list<Student>& roster, string fileName);
// printing a list out
void printRoster(const list<Student>& roster);

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0]
      << " list of courses, dropouts last" << endl; exit(1);}

    list<Student> roster;
    for (int i = 1; i < argc - 1; i++) {
        readRoster(roster, argv[i]);
    }
    
    // Reading in the dropouts
    list<Student> dropouts;
    readRoster(dropouts, argv[argc - 1]);
    

    // Removing dropouts
    for (const auto& str : dropouts) {
        roster.remove(str);
    }
    
    printRoster(roster);
}



void readRoster(list<Student>& roster, string fileName) {
    ifstream course(fileName);
    string courseName = fileName; // setting file name into a string
    courseName.erase(courseName.end() - 4, courseName.end()); // removing the .txt part of the fileName by erasing from the . to the t
    string first, last;
    
    while(course >> first >> last) {
        bool check = false;
        for (auto& student : roster) {
            if (student.get_firstName_() == first && student.get_lastName_() == last) {
                student.addCourse(courseName);
                check = true;
                break;
            }
        }
        if (!check) {
            roster.push_back(Student(first, last, courseName));
        }
        
    }
    course.close();
}

// printing a list out
void printRoster(const list<Student>& roster){
    for(auto student : roster) {
        cout << student.print() << " ";
        student.printList();
        cout << endl;
    }
}




