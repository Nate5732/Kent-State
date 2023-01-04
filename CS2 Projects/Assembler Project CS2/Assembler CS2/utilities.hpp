// Nathon Iadimarco
// utilities.hpp file
// CS2
#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"
#include <fstream>

String infix2postfix(std::ifstream& in, std::ostream& out);
String evaluate(String& left, String& right, String& oper, int tmp);
String opercodes(String oper);
String toAssembly(String expr);
String int2string(int x);


#endif
