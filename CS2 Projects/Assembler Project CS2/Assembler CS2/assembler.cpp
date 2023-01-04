// Nathon Iadimarco
// CS2
// assembler main file
#include "stack.hpp"
#include "utilities.hpp"
#include <fstream>
#include <iostream>


int main(int argc, char *argv[]) {

    if (argc == 1) {
        std::cerr << "No input file in arguments, please specificy an input file." << std::endl;
    }

    std::ifstream inputFile(argv[1]);

    if (!inputFile) {
        std::cerr << "File containing data could not be read or opened." << std::endl;
    }

    if (argc == 2) {
        while (!inputFile.eof()) {
            std::cout << "Infix Expression: ";
            String infix2PostValue = infix2Postfix(inputFile, std::cout);

            if(inputFile.eof()) break;

            std::cout << std::endl;
            std::cout << "Postfix Expression: " << infix2PostValue << std::endl;
            std::cout << toAssembly(infix2PostValue) << std::endl;
        }
    }
    
    std::ofstream assemblyFile(argv[2]);
    if (argc == 3) {
        while (!inputFile.eof()) {
            assemblyFile << "Infix Expression: ";
            String infix2PostValue = infix2Postfix(inputFile, assemblyFile);

            if(inputFile.eof()) break;

            assemblyFile << std::endl;
            assemblyFile << "Postfix Expression: " << infix2PostValue << std::endl;
            assemblyFile << toAssembly(infix2PostValue) << std::endl;
        }
    }
    assemblyFile.close();
    inputFile.close();
}
