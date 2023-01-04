#include "stack.hpp"
#include <iostream>
#include <string>
typedef std::string String;

//expr - must be valid fully paranthesized infix expression
String infix_to_postfix(const char expr[]) {
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

int main() {
    
}
