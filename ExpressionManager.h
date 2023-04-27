#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;

bool isOperator(char c);
bool isLeftParenthesis(char c);
bool isRightParenthesis(char c);
int getPrecedence(char c);
string infixToPostfix(string expression);
bool hasBalancedParentheses(string expression);

#endif