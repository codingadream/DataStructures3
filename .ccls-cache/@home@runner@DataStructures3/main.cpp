#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include "ExpressionManager.h"


using namespace std;


int main() {
    std::string expression;

    // Read an infix expression from the user
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, expression);

    // Check if the expression has balanced parentheses
    if (!hasBalancedParentheses(expression)) {
        std::cout << "Invalid Expression: Unmatched Parentheses" << std::endl;
        return 0;
    }

    // Convert the infix expression to postfix expression
    std::string postfix = infixToPostfix(expression);

    // Display the postfix expression
    std::cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}
