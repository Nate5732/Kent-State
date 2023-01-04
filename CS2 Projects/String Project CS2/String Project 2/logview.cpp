// File:        main.cpp
//
// Version:     1.1
// Date:        Fall 2022
// Author:
//
// Description: Main body for logview application
//

////////////////////////////////////////////////////////////
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "string.hpp"
#include "logentry.hpp"


////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    // Options
    std::vector<String> option(3);
    option[0] = "all";
    option[1] = "bytes";
    option[2] = "host";

    if (argc != 3) {      // Error if there are not 3 things on the command line
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " [ "
        << option[0] << " | "
        << option[1] << " | "
        << option[2] << " ] log_file" << std::endl;
        exit(1);         // Exit with error
    }

    std::ifstream in(argv[2]);     // Open file, quit if open fails
    if (!in) {
        std::cerr << "Error: Can not open " << argv[2] << std::endl;
        exit(2);
    }
    std::vector<LogEntry> log_entries = parse(in);   // Process the log file
    in.close();

    if (argv[1] == option[0]) {                // Handle the specified option
        output_all(std::cout, log_entries);
    }
    else if (argv[1] == option[1]) {
        std::cout << "Total number of bytes sent: "
                  << byte_count(log_entries) << std::endl;
    }
    else if (argv[1] == option[2]) {
        by_host(std::cout, log_entries);
    }
    else { //Error, bad option
        std::cerr << "Unrecognized option: " << argv[1] << std::endl;
        std::cerr << "Recognized options: "
             << option[0] << " "
             << option[1] << " "
             << option[2] << std::endl;
        exit(3);
    }
    return 0;
}
