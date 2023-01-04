#============================================================================
# Assembler and Stack
#
# CS II Kent State University
# J. Maletic Fall 2022
#
#
#  Makefile works for string.cpp in either local (.) or ../string/
#
###############################################################
# Variables
CPP          = clang++
CPP_FLAGS    = -g -Werror -W -Wunused -Wuninitialized -Wshadow -std=c++17
INCLUDE_OPT  = -I ../string/
VPATH        = src:../string/
STRING_PATH  = $(shell if test -f string.cpp; then echo ""; else echo "../string/"; fi)


#===========================================================================
# Your STACK tests here.
STACK_TESTS =  test_ctor_default test_push_pop test_assign test_ctor_copy


#===========================================================================
msg:
        @echo 'Targets for compiling test programs:'
        @echo '   tests     - Compile and run tests for stack (Milestone 1)'
        @echo '   postfix   - Compile and run postfix tests   (Milestone 2)  '
        @echo '   assembler - Compile and run assembler code  (Milestone 3)'
        @echo '   string    - Compile string'
        @echo '   clean     - Removes all .o and executables'

#===========================================================================
# Compile string.o from Project 2.

string.o:       string.hpp  string.cpp
        ${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c ${STRING_PATH}string.cpp

string: string.hpp  string.cpp
        ${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c ${STRING_PATH}string.cpp


#===========================================================================
# No compile for stack - it is a template.


#===========================================================================
# Compile test programs for stack
test_%: string.o test_%.o
        ${CPP} ${CPP_FLAGS} string.o test_$*.o -o test_$*

test_%.o: string.hpp string.cpp stack.hpp test_%.cpp
        ${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c test_$*.cpp


#===========================================================================
# Run test programs
# INSERT your tests for the stack here.
tests: stack.hpp string.hpp string.cpp ${STACK_TESTS}
        ./test_ctor_default
        ./test_push_pop
#       ./test_assign
#       ./test_ctor_copy
#   ./test_dtor


#===========================================================================
# Compile and run milestone 1 instructor tests
# Can only be done by instructor
M1_PATH = ../../instructors/project3/
M1_TESTS = M1_ctor_default M1_push_pop M1_empty M1_assign M1_ctor_copy M1_swap

M1_%: M1_%.o string.o
        ${CPP} ${CPP_FLAGS} string.o M1_$*.o -o M1_$*

M1_%.o: string.hpp string.cpp stack.hpp ${M1_PATH}M1_%.cpp
        cp ${M1_PATH}M1_$*.cpp .
        ${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c M1_$*.cpp

M1: stack.hpp string.hpp string.cpp ${M1_TESTS}
        ./M1_ctor_default
        ./M1_push_pop
        ./M1_ctor_copy
        ./M1_swap
        ./M1_assign
        ./M1_empty

M1MEM: stack.hpp string.hpp string.cpp ${STACK_TESTS}
        valgrind ./M1_ctor_default
        valgrind ./M1_push_pop
        valgrind ./M1_ctor_copy
        valgrind ./M1_swap
        valgrind ./M1_assign
        valgrind ./M1_empty



#===========================================================================
# Compile postfix

utilities.o: utilities.cpp utilities.hpp string.cpp string.hpp stack.hpp
        ${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c utilities.cpp

postfix.o: postfix.cpp string.hpp string.cpp stack.hpp utilities.hpp
        ${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c postfix.cpp

postfix: postfix.o string.o utilities.o
        ${CPP} ${CPP_FLAGS} postfix.o string.o utilities.o -o postfix

#===========================================================================
# Compile assembler

assembler.o: assembler.cpp string.hpp string.cpp stack.hpp utilities.hpp
        ${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c assembler.cpp

assembler: assembler.o string.o utilities.o
        ${CPP} ${CPP_FLAGS} string.o assembler.o  utilities.o -o assembler



#============================================================================
clean:
        rm -f *.o
        rm -f postfix
        rm -f assembler
        rm -f $(STACK_TESTS)
        rm -f $(UTILS_TESTS)
        rm -f $(M1_TESTS)
        rm -f M1_*

