#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Invalid parameters" << std::endl;
        std::cout << "Usage: ./RPN <parameters>" << std::endl;
        return 1;
    }
    RPN calculator;
    calculator.executeExpression(argc, argv);
    return 0;
}