#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN {
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void performOperations(const std::string& operation);
        void executeExpression(int argc, char **argv);
};

#endif