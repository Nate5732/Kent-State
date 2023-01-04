// Nathon Iadimarco
// postfix.cpp file
// CS2
#include "stack.hpp"
#include "utilities.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "No file found" << std::endl;
        return 0;
    }
    
    std::ifstream infix (argv[1]);
    if (!infix) {
        std::cout << "Infix file not found" << std::endl;
    }
    
    if (argc == 2) {
        while (!infix.eof()) {
            String v1 = infix2postfix(infix, std::cout);
            std::cout << v1 << std::endl;
        }
    }
    
    if (argc == 3) {
        std::ofstream postfix(argv[2]);
        if (!postfix) {
            std::cout << "Postfix file not found" << std::endl;
        } else {
            while (!infix.eof()) {
                String v2 = infix2postfix(infix, postfix);
                postfix << v2 << std::endl;
            }
        }
        postfix.close();
    }
    infix.close();
}
