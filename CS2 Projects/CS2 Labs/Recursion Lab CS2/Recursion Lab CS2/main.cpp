//
//  main.cpp
//  Recursion Lab CS2
//
//  Created by Nathon Iadimarco on 10/25/22.
//

#include <iostream>

//Recursion
int Fibrec(int x) {
    if (x <= 1) {
        return x;
    } else {
        return Fibrec(x - 1) + Fibrec(x - 2);
    }
}

//Tail Recursion
int Fibtail(int n, int x = 0, int a = 1) {
    if (n == 0) {
        return x;
    } else if (n == 1) {
        return a;
    } else {
    return Fibtail(n - 1, a, x + a);
    }
}
 

int main() {
    std::cout << "recursive = " << Fibrec(9) << std::endl;
    std::cout << "tail recursive = " << Fibtail(9) << std::endl;
}
