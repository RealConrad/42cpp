#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other): stack(other.stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->stack = other.stack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::performOperations(const std::string& operation) {
    if (this->stack.size() < 2) {
        std::cout << "Error: Not enough operands" << std::endl;
    }
    int result = 0;
    int operand2 = this->stack.top();
    this->stack.pop();
    int operand1 = this->stack.top();
    this->stack.pop();

    if (operation == "+")
        result = operand1 + operand2;
    else if (operation == "-")
        result = operand1 - operand2;
    else if (operation == "*")
        result = operand1 * operand2;
    else if (operation == "/") {
        if (operand2 == 0) {
            std::cout << "Error: Cannot by 0" << std::endl;
            exit(1);
        }
        result = operand1 / operand2;
    } else {
        std::cout << "Error: Invalid operation: " << operation << std::endl;
        exit(1);
    }
    this->stack.push(result); // add the result back to the stack for the next operation
}

void RPN::executeExpression(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        std::string token = argv[i];
        if (token.length() == 1 && std::isdigit(token[0])) { // if false - we've hit an operand (+ - * /)
            std::istringstream iss(token);
            int operand;
            iss >> operand;
            this->stack.push(operand);
        } else {
            performOperations(token);
        }
    }
    std::cout << "Result: " << this->stack.top() << std::endl;
}
