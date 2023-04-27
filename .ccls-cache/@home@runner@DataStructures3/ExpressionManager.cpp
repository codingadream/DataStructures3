#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;
#include "ExpressionManager.h"
#include <stack>

// Function to check if the given character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Function to check if the given character is a left parenthesis
bool isLeftParenthesis(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if the given character is a right parenthesis
bool isRightParenthesis(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// Function to get the precedence of the given operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
std::string infixToPostfix(std::string expression) {
    std::stack<char> s;
    std::string postfix = "";

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // If current character is a whitespace, skip it
        if (c == ' ') {
            continue;
        }

        // If current character is an operand, add it to the postfix expression
        if (isdigit(c) || isalpha(c)) {
            postfix += c;
        } else if (isOperator(c)) {
            // If current character is an operator, pop operators with higher or equal precedence from the stack and add them to the postfix expression
            while (!s.empty() && isOperator(s.top()) && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            // Push the current operator onto the stack
            s.push(c);
        } else if (isLeftParenthesis(c)) {
            // If current character is a left parenthesis, push it onto the stack
            s.push(c);
        } else if (isRightParenthesis(c)) {
            // If current character is a right parenthesis, pop operators from the stack and add them to the postfix expression until a matching left parenthesis is found
            while (!s.empty() && !isLeftParenthesis(s.top())) {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && isLeftParenthesis(s.top())) {
                s.pop();
            } else {
                // If there is no matching left parenthesis, the expression is invalid
                return "Invalid Expression: Unmatched Right Parenthesis";
            }
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (!s.empty()) {
        if (isLeftParenthesis(s.top())) {
            // If there is a left parenthesis on the stack, the expression is invalid
    return "Invalid Expression: Unmatched Left Parenthesis";
    }
    postfix += s.top();
    s.pop();
}

return postfix;
}

bool hasBalancedParentheses(std::string expression) {
std::stack<char> s;
for (int i = 0; i < expression.length(); i++) {
    char c = expression[i];

    if (isLeftParenthesis(c)) {
        s.push(c);
    } else if (isRightParenthesis(c)) {
        if (s.empty()) {
            return false;
        }
        char top = s.top();
        if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
            s.pop();
        } else {
            return false;
        }
    }
}

return s.empty();
}

