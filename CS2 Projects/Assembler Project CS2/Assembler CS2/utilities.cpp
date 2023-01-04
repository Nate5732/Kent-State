// Nathon Iadimarco
// utilities.cpp file
// CS2
#include "utilities.hpp"
#include "stack.hpp"
#include <iostream>

String infix_to_postfix(std::ifstream& in, std::ostream& out) {
    stack<String> S;
    char token[400];
    String rhs, oper, lhs, currentToken;
    
    while (!in.eof()) {
        in >> token;
        currentToken = token;
        out << currentToken << " ";
        if (in.eof()) break;
        if (currentToken == ";") {
            return S.top();
        } else if (currentToken == ")") {
            rhs = S.pop();
            oper = S.pop();
            lhs = S.pop();
            S.push(lhs + rhs + oper);
        } else if (currentToken != "(") {
            S.push(currentToken + ' ');
        }
    }
    return "";
}

String opcodes(String oper) {
    if (oper == "+") {
        return "Addition";
    } else if (oper == "*") {
        return "Multiplication";
    } else if (oper == "-") {
        return "Subtraction";
    } else if (oper == "/") {
        return "Division";
    } else {
        return "Invalid input " + oper;
    }

}

String evaluate(String& left, String& right, String& oper, int tmp) {
    String NUM = int2string(tmp);
    return "    LD     " + left + "\n" + "    " + opcodes(oper) + "     " + right + "\n" + "    ST     " + "TMP" + NUM + "\n";
}


String int2string(int x) {
    if (!x) {
        return "0";
    }
    String result;
    
    while (x > 0) {
        result += (x % 10 + 48);
        x /= 10;
    }
    return result;
}

String toAssembly(String expr) {
    
    if (expr == "") return "String is empty. ";
    
    stack<String> holder;
    String left, right, oper, result;
    String evalNow;
    int temp = 1;

    std::vector<String> exprHolder = expr.split(' ');

    for (size_t i = 0; i < exprHolder.size(); ++i) {
        String currentToken = exprHolder[i];
        if (currentToken != "+" && currentToken != "-" && currentToken != "*" && currentToken != "/") {
            holder.push(currentToken);
        } else {
            right = holder.pop();
            left = holder.pop();
            evalNow += evaluate(left, right, exprHolder[i], temp);
            holder.push("TMP" + intToString(tmpCounter));
            temp++;
        }
    }
    return evalNow;
}
