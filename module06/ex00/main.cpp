#include "ScalarConverter.hpp"

int main() {
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("4.0f");
    ScalarConverter::convert("4.12");
}
