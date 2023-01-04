#include <iostream>

using std::cout; using std::cin; using std::endl;


int main () {
const int SIZE=10;
int myarray[SIZE];

int number;
cout << "Input the number to search for: ";
cin >> number;
    
    bool found=false;
    for(int i=0; i < SIZE; ++i)
        if (myarray[i]== number)
            found= true;
    if (found)
        cout << "FOUND";
    else
            cout << "NOT FOUND";
    
    
}



