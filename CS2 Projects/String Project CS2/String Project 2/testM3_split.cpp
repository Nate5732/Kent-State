// string Test Program
//
// Tests Split using vector
//
// Nathon Iadimarco
#include "string.hpp"
#include <iostream>
#include <cassert>
#include <vector>

int main () {

    {
    String str("abc ef gh");
    std::vector<String> give = {"abc", "ef", "gh"};
        
    std::vector<String> result = str.split(' ');

    assert(result == give);
    }

    {
    String str("-a--b-");
    std::vector<String> give = {"", "a", "", "b", ""};

    std::vector<String> result = str.split('-');
       
    assert(give == result);
    }
    
    {
    String str("Nathon Iadimarco");
    std::vector<String> give = {"Nathon", "Iadimarco" };

    std::vector<String> result = str.split(' ');
       
    assert(give == result);
    }
    
    {
    String str;
    std::vector<String> give = {""};

    std::vector<String> result = str.split(' ');
       
    assert(give == result);
    }

    {
    String str("h e l l o");
    std::vector<String> give = {"h", "e", "l", "l", "o"};

    std::vector<String> result = str.split(' ');
       
    assert(give == result);
    }
    
    {
    String str("Nathon--Iadimarco");
    std::vector<String> give = {"Nathon", "", "Iadimarco"};

    std::vector<String> result = str.split('-');
       
    assert(give == result);
    }
    
    {
    String str("TestAlot");
    std::vector<String> give = {"TestAlot"};

    std::vector<String> result = str.split(' ');
       
    assert(give == result);
    }
    
    {
    String str("-wo--rk-");
    std::vector<String> give = {"", "wo", "", "rk", ""};

    std::vector<String> result = str.split('-');
       
    assert(give == result);
    }
    
    {
    String str("Splitting A String");
    std::vector<String> give = {"Splitting", "A", "String"};

    std::vector<String> result = str.split(' ');
       
    assert(give == result);
    }
    
    {
    String str("Double  Space");
    std::vector<String> give = {"Double", "", "Space"};

    std::vector<String> result = str.split(' ');
       
    assert(give == result);
    }
    
    {
    String str("arcade");
    std::vector<String> give = {"arca", "e"};

    std::vector<String> result = str.split('d');
       
    assert(give == result);
    }
    
    std::cout << "Done testing split function " << std::endl;
}
