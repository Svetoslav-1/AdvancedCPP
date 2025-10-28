#include <iostream>
#include <queue>
#include <stack>
using namespace std; 

/*
Given a sequence consisting of parentheses, determine whether the expression is balanced. A sequence of
parentheses is balanced if every open parenthesis can be paired uniquely with a closing parenthesis that occurs
after the former. Also, the interval between them must be balanced. You will be given three types of
parentheses: (, {, and [.
{[()]} – This is a balanced parenthesis.
{[(])} – This is not a balanced parenthesis.
Input
● Each input consists of a single line, the sequence of parentheses */

bool isBalanced(const std::string& parentheses) { 
    std::stack<char> buffer;

    for (char c : parentheses) {
        if (c == '(' || c == '{' || c == '[') {
            buffer.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (buffer.empty()) {
                return false;  
            }

            char top = buffer.top();
            buffer.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false; 
            }
        }
    }

    return buffer.empty(); 
}

int main() {
    std::string parentheses;
    std::cin >> parentheses;

    if (isBalanced(parentheses)) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
