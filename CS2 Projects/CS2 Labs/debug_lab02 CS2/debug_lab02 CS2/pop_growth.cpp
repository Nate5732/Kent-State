#include <iostream>

const int STRING_SIZE = 512 ;   //increase the size

int calculatePopulation(double, double);

int main() {

  std::cout << "Enter the name of the university\n";
  char univName [STRING_SIZE];   // Is length a issue here
  std::cin.getline(univName, STRING_SIZE);

  char done = 'N';
  while(!(done == 'Y') || !(done == 'y')) {   // "=" or "=="
    
    std::cout << "What is the current population? ";
    int pop;
    std::cin >> pop;
    while(pop < 1) {
      std::cout << pop << ": Invalid Input Error!\n";
      return -1;
    }

    std::cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
    int growth;
    std::cin >> growth;
    while(growth < 0) {
      std::cout << growth << ": Invalid Input Error!\n";
      return -1;
    }

    std::cout << "\nYear\tNew Population" << std::endl;
    int *newpop = new int;
    for (int i = 1; i <= 5; i++) {
      *newpop = calculatePopulation( pop , growth );
      pop = *newpop;
      std::cout << i << "\t \t" << *newpop << std::endl;
      //delete newpop;   //Delete here will create trouble
    }
    

     std::cout << "\nFinal population of " << univName;
     std::cout << " is " << *newpop << std::endl;
     
     std::cout << "Done? (Y/N) ";
     std::cin >> done;
     switch (toupper(done)) {
       case 'Y':
         std::cout << "Exiting...\n";
         return 0;
       case 'N':
         std::cout << "Starting again\n";
         std::cout << "------------------------------\n";
         break;
       default:
         std::cout << ": Invalid input\n";
         std::cout << "The program will exit\n";
         std::cout << "------------------------------\n";
         return -1;
       }
   }
   return 0;
 }

 int calculatePopulation( double pop, double growth) {
   double growthRate = (double) growth / 100;
   double increase = (double) pop * growthRate;
   return (pop + increase);
     
 }
