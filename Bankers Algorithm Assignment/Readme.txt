Programming Assignment #2
Operating Systems

This program built with C++ is an implementation of the Bankers Algorithm and detects whether or not the system is or is not in a safe state.
The program checks for possibility of deadlock and if none can occur, it reads in data from a .txt file (input.txt) and will print the safe sequence.

Instructions for Compilation:
g++ banke.cpp -o banker
./banker

Example outputs for this program include:
Not in safe state.

or:

In Safe State
Safe sequence is: P1 P3 P4 P0 P2


Within the input.txt file is three rows of numbers. 
The first, second, and third rows are for the Allocation, Max, and Available arrays respectively.
