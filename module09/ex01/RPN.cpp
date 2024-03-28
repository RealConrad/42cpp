#include "RPN.hpp"
#include <exception>
RPN::RPN() {}

RPN::RPN(const RPN& other): stack(other.stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->stack = other.stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::performOperations(char operation) {
	if (this->stack.size() < 2)
		throw std::invalid_argument("Not enough digits inside stack");
	double result = 0;
	double operand2 = this->stack.top();
	this->stack.pop();
	double operand1 = this->stack.top();
	this->stack.pop();

	switch (operation) {
		case '+':
			result = operand1 + operand2;
			break;
		case '-':
			result = operand1 - operand2;
			break;
		case '*':
			result = operand1 * operand2;
			break;
		case '/':
			if (operand2 == 0) {
				throw std::invalid_argument("Cannot divide by 0");
			}
			result = operand1 / operand2;
			break;
		default:
			throw std::invalid_argument("Unknown operation");
	}
	this->stack.push(result); // add the result back to the stack for the next operation
}

void RPN::executeExpression(const std::string& expr) {
	bool last_char = true;

	for (size_t i = 0; i < expr.size(); ++i) {
		char ch = expr[i];
		if (std::isspace(static_cast<unsigned char>(ch)))
		{	
			last_char = true;
			continue;
		}
		else
		{
			if (last_char == false)
				throw std::invalid_argument("Number is not a digit");
			else
				last_char = false;
		}
		if (std::isdigit(static_cast<unsigned char>(ch)) != 0) {
			stack.push(ch - '0');
		} else {
			performOperations(ch);
		}
	}

	if (stack.size() > 1)
		throw std::invalid_argument("Invalid stack size");
	std::cout << "Result: " << this->stack.top() << std::endl;
}
