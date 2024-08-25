// Nathon Iadimarco Lab4
// vector and list algorithms
// Mikhail Nesterenko
// 3/11/2014
/*
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

// reading a list from a fileName
void readRoster(vector<list<string>>& roster, string fileName);

// printing a list out
void printRoster(const vector<list<string>>& roster);

int main(int argc, char* argv[]){

   if (argc <= 1){
      cout << "usage: " << argv[0]
      << " list of courses, dropouts last"
      << endl;
      exit(1);
   }

   // vector of courses of students
   vector <list<string>> courseStudents;

   for(int i=1; i < argc; ++i){
       readRoster(courseStudents, argv[i]);
   }
    
    printRoster(courseStudents);
    cout << "all students with dropouts removed." << endl;
    
}

// reading in a file of names into a list of strings
void readRoster (vector<list<string>>& courseStudents, string fileName){
    ifstream course(fileName); // Creating file stream
    string courseName = fileName; // Grabbing the course name from the file name
    courseName.erase(courseName.end() - 4, courseName.end()); // removing the .txt part of the fileName by erasing from the . to the t
    string first, last;
    while(course >> first >> last) {
        bool check = false; // Used to check if there is a name match and whether or not to continue adding.
        for (auto i = courseStudents.begin(); i != courseStudents.end(); ++i) { // for loop that is looping through list of strings. (students)
            if (i->front() == first && *(++(i->begin())) == last) { // Checking if first and last names match any students in list, if so add the course they were found in to their name in list.
                if (courseName== "dropouts"){
                    courseStudents.erase(i);
                    check=true;
                    break;
                } else {
                    check = true;
                    i->push_back(courseName); // Pushing courseName.
                    break;
                }
            }
        }
        
        if (!check) { // Otherwise if check is still false, student entry is not read yet so we add it in.
            list<string> name;
            name.push_back(first); // Pushing first name.
            name.push_back(last); // Pushing last name.
            name.push_back(courseName); // Adding in the courseName.
            courseStudents.push_back(move(name)); // Moving the student entry into the container.
        }
    }
    course.close(); // closing file that has been read.
}

// printing a list out
void printRoster(const vector<list<string>>& courseStudents) {
    for(auto i = courseStudents.begin(); i != courseStudents.end(); ++i) {
        for (auto& student : *i) {
            cout << student << " ";
        }
        cout << endl;
    }
}


*/
