#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <stack>
#include "ExpressionManager.h"
 
using namespace std; 

 // Check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// check if character is left parenthesis
bool isLeftParenthesis(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Check if character is a right parenthesis
bool isRightParenthesis(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// gets pre-existence of given operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string expression) {
    stack<char> s;
    string postfix = "";

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

bool hasBalancedParentheses(string expression) {
stack<char> s;
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

