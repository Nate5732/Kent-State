// Nathon Iadimarco
// Infix2Prefix Lab
// CS2
#include <iostream>
#include <string>
#include "stack.hpp"

typedef std::string String;

String infix2prefix(const char expr[]) {
    stack<String> S;
    int i = 0;
    String lhs, op, rhs, temp=" ";
    while (expr[i] != 0) {
        if (expr[i] == ')') {
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(lhs + rhs + op);
        }else if (expr[i] != ')') {
            temp[0]= expr[i];
            S.push(temp);
        }
        ++i;
    }
    return S.pop();
}

int main(int argc, char *argv[]) {
    
}
