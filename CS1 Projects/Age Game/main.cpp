// Troll Age Guessing Game
// Nathon Iadimarco
// 2/14/2022

#include <iostream>
#include <ctime>

using std::endl; using std::cin; using std::cout;

int main() {
    //srand(time(nullptr));
    srand(2);
    int age = rand() % 101 + 100;
    int guess = -1;
    int year = 1000;

    do {
        cout << "The year is " << year << " Hello, handsome prince. I am an ugly old troll. How old am I?" << endl;
        cin >> guess;
        if (guess < age) {
            cout << "Wrong, I am older. No fair maiden for you. See you in five years." << endl;
            year += 5;
            age += 5;
            guess = -1;
        }
            
        else if (guess > age) {
            cout << "Wrong, I am younger. No fair maiden for you. See you in five years." << endl;
            year += 5;
            age += 5;
            guess = -1;

        }
        else if (guess == age) {
            cout << "You got it! Here is the fair maiden. Live happily ever after!" << endl;

        }
        
    } while (guess != age);

}

