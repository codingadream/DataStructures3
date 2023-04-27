#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <iostream>
#include <fstream>
#include <array>


#include <string>

bool isOperator(char c);
bool isLeftParenthesis(char c);
bool isRightParenthesis(char c);
int getPrecedence(char c);
std::string infixToPostfix(std::string expression);
bool hasBalancedParentheses(std::string expression);

#endif