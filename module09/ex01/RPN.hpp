#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

class RPN {
    private:
        std::stack<double> stack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void performOperations(char operation);
        void executeExpression(const std::string& expr);
};

#endif