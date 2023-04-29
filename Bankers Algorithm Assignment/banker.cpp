// Nathon Iadimarco
// Operating Systems
// 4/28/2023
// banker.cpp

#include <iostream>
#include <fstream>
#include <sstream>

// Number of Processes and Resources
const int numProcesses = 5;
const int numResources = 3;

bool safeState(int Processes[], int available_resources[], int max_required[][numResources], int alloted[][numResources]) { //Safe State

    int need[numProcesses][numResources];

    for (int i = 0 ; i < numProcesses ; i++) {

        for (int j = 0 ; j < numResources ; j++) {

            need[i][j] = max_required[i][j] - alloted[i][j];

        }

    }

    int safe_sequence[numProcesses];
    bool finish[numProcesses] = {0};
    int curr_available[numResources];

    for (int i = 0; i < numResources ; i++) curr_available[i] = available_resources[i];

    int index = 0;

    while (index < numProcesses) {

        bool found = false;
        for (int p = 0; p < numProcesses; p++) {

            if (finish[p] == 0) {

                int j;
                for (j = 0; j < numResources; j++) {

                    if (need[p][j] > curr_available[j]) break;

                }

                if (j == numResources) {

                    for (int k = 0 ; k < numResources ; k++) {

                        curr_available[k] += alloted[p][k];

                    }

                    safe_sequence[index] = p;
                    ++index;
                    finish[p] = 1;

                    found = true;

                }

            }

        }

        if (found == false) { // If not in safe state, announce.

            std::cout << "Not in safe state.";

            return false;

        }

    }

    std::cout << "In Safe State\nSafe sequence is: "; // If in safe state, denounce the safe sequence.

    for (int i = 0; i < numProcesses ; i++) std::cout << "P" << safe_sequence[i] << " "; // Outputting the Safe Sequence
    std::cout << "\n";

    return true;
}

int main() {
    int i, j, looping;
    int Allocation[5][3];
    int Max[5][3];
    int Available[3] = {3, 3, 2};

    int f[numProcesses], ans[numProcesses], index = 0;

    std::ifstream file;
    file.open("input.txt");

    for (int m = 0; m < numProcesses; ++m) {
        for (int l = 0; l < numResources; ++l) {
            
        
            if (file.is_open()) {
                std::string line;

                std::getline(file, line, ' ');
            
                std::stringstream ss;
                ss << line;
                int output;
                ss >> output;
                Allocation[m][l] = output;
            }
        }
    }

    for (int m = 0; m < numProcesses; ++m) {
        for (int l = 0; l < numResources; ++l) {
            
        
            if (file.is_open()) {
                std::string line;

                std::getline(file, line, ' ');
            
                std::stringstream ss;
                ss << line;
                int output;
                ss >> output;
                Max[m][l] = output;
                
            }
        }
    }

    for (int m = 0; m < numResources; ++m) {
        
        if (file.is_open()) {
           std::string line;

            std::getline(file, line, ' ');
            
            std::stringstream ss;
            ss << line;
            int output;
            ss >> output;
            Available[m] = output;
            
        }
    }

    int Processes[] = {0, 1, 2, 3, 4};
    safeState(Processes, Available, Max, Allocation);
}