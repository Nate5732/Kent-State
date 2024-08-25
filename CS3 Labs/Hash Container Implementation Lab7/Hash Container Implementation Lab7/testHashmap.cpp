// Nathon Iadimarco
// CS3 Lab7
// Testing hashmap

// demoes hashmap implementation
// Mikhail Nesterenko
// 4/15/2014
/*
#include "hashmap.hpp"
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
   hashmap<int, int> myHash;
   myHash.insert(pair<int,int>(4, 40));
   myHash.insert(make_pair(6, 60));

   // x will have type hashmap<int, int>::value_type*
   auto x = myHash.find(4);
   if (x != nullptr)
      cout << "4 maps to " << x->second << endl;
   else
      cout << "cannot find 4 in map" << endl;
   

   myHash.erase(4);

   auto x2 = myHash.find(4);
   if (x2 != nullptr)
      cout << "4 maps to " << x2->second << endl;
   else
      cout << "cannot find 4 in map" << endl;
   
   myHash[4] = 35;
   myHash[4] = 60;

   auto x3 = myHash.find(4);
   if (x3 != nullptr)
      cout << "4 maps to " << x3->second << endl;
   else
      cout << "cannot find 4 in map" << endl;

   hashmap<int, string> employees;

   // entering entries with indexing operator
   employees[123] = "Mike";
   employees[345] = "Charlie";
   employees[192] = "Joe";
   employees[752] = "Paul";
   employees[328] = "Peter";

   cout << "Enter new employee number: "; int num; cin >> num;
   cout << "Enter new employee name: "; string name; cin >> name;

   employees[num] = name; // "unsafe" insert

   // searching map
   cout << "Enter employee number to look for: "; cin >> num;
   auto it = employees.find(num);
   if(it != nullptr)
      cout << it->first << ":" << it->second << endl;
   else
      cout << "employee not found" << endl;

   // removing from a map
   cout << "Enter employee number to fire: "; cin >> num;
   employees.erase(num);
   // check if not there
   auto removed = employees.find(num);
   if (removed == nullptr)
      cout << "Employee removed successfully" << endl;

}*/


// hashmap test file
// Mikhail Nesterenko,  Tsung-Heng Wu
// 3/6/2024

#include "hashmap.hpp"
#include <iostream>
#include <string>
#include <cassert>

using std::string;

int main() {
    
    //
    // <int, int> hashmap test
    //
    hashmap<int, int> myHash;
    
    // test inserts
    pair<const pair<const int, int>*, bool> result;
    
    result = myHash.insert(make_pair(4, 40));
    assert(result.second);
    assert(result.first->first == 4);
    assert(result.first->second == 40);
    
    result = myHash.insert(make_pair(105, 1050));
    assert(result.second);
    assert(result.first->first == 105);
    assert(result.first->second == 1050);
    
    result = myHash.insert(make_pair(6, 60));
    assert(result.second);
    assert(result.first->first == 6);
    assert(result.first->second == 60);
    
    result = myHash.insert(make_pair(107, 1070));
    assert(result.second);
    assert(result.first->first == 107);
    assert(result.first->second == 1070);
    
    result = myHash.insert(make_pair(90, 900));
    assert(result.second);
    assert(result.first->first == 90);
    assert(result.first->second == 900);
    
    result = myHash.insert(make_pair(95, 950));
    assert(result.second);
    assert(result.first->first == 95);
    assert(result.first->second == 950);
    
    result = myHash.insert(make_pair(6, 70)); // insert with a duplicate key
    assert(!result.second);
    assert(result.first->first == 6);
    assert(result.first->second == 60);
    
    
    // searching map
    // x will have type hashmap<int, int>::value_type*
    auto x = myHash.find(4);
    assert(x != nullptr);
    assert(x->second == 40);
    
    x = myHash.find(5);
    assert(x == nullptr);
    
    
    // test deletes
    result = myHash.erase(4); // delete with next element in same bucket
    assert(result.second);
    assert(result.first->first == 105);
    assert(result.first->second == 1050);
    
    result = myHash.erase(107); // delete the last element in a bucket
    assert(result.second);
    if (result.first != nullptr) { // Ensure result.first is not nullptr
        assert(result.first->first == 90);
        assert(result.first->second == 900);
    }
    
    result = myHash.erase(6);
    assert(result.second);
    if (result.first != nullptr) { // Ensure result.first is not nullptr
        assert(result.first->first == 90);
        assert(result.first->second == 900);
    }
    
    result = myHash.erase(105); 
    assert(result.second);
    if (result.first != nullptr) { // Ensure result.first is not nullptr
        assert(result.first->first == 90);
        assert(result.first->second == 900);
    }
    
    result = myHash.erase(95); // erase the last element in the container
    assert(result.second);
    assert(result.first== nullptr);
    
    result = myHash.erase(90); // erased all elements in container
    assert(result.second);
    assert(result.first == nullptr);
    
    result = myHash.erase(5); // erase key not in container
    assert(!result.second);
    // first is unspecified
    
    
    //
    // <integer, string> hashmap test
    //
    hashmap<int, string> employees;
    
    // add tests for insert using the <integer, string> hashmap
    pair<const pair<const int, string>*, bool> result_str_insert;
    
    result_str_insert = employees.insert(make_pair(123, "Mike"));
    assert(result_str_insert.second);
    assert(result_str_insert.first->first == 123);
    assert(result_str_insert.first->second == "Mike");
    
    // add tests for find using the <integer, string> hashmap
    auto found_employee = employees.find(123);
    assert(found_employee != nullptr);
    assert(found_employee->second == "Mike");
    
    // add tests for erase using the <integer, string> hashmap
    pair<const pair<const int, string>*, bool> result_str_erase;
    result_str_erase = employees.erase(123);
    assert(result_str_erase.second);
    
    // add tests for [] operator using the <integer, string> hashmap
    employees[345] = "Charlie";
    assert(employees[345] == "Charlie");
    
    // add tests for rehash
    employees.rehash(10);
    
    // check the hashmap is still correct and all operations still work after rehash
    auto found_employee_after_rehash = employees.find(345);
    assert(found_employee_after_rehash != nullptr);
    assert(found_employee_after_rehash->second == "Charlie");
    
    std::cout << "Tests passed" << std::endl;
}

