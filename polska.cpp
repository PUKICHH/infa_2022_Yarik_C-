#include <iostream>
#include <stack>

std::string postfix(std::string input) {
    std::stack<char> stk;
    std::string output;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            stk.push(input[i]);
        } else if (input[i] == ')') {
            while (stk.top() != '(') {
                output += stk.top();
                stk.pop();
            }
            stk.pop();
        } else if (input[i] == '*' or input[i] == '/') {
            if (stk.size() != 0 and stk.top() == '~') {
                output += '~';
                stk.pop();
            }
            stk.push(input[i]);
            output += ' ';
        } else if (input[i] == '~') {
            stk.push(input[i]);
        } else if (input[i] == '+' or input[i] == '-') {
            if (stk.size() != 0 and stk.top() == '~') {
                output += '~';
                stk.pop();
            }
            while (stk.size() != 0 and stk.top() != '(') {
                output += stk.top();
                stk.pop();
            }
            stk.push(input[i]);
            output += ' ';
        } else output += input[i];
    }
    int size = stk.size();
    for (int i = 0; i < size; i++) {
        output += stk.top();
        stk.pop();
    }
    return output;
}

int post_calc(std::string input) {
    std::stack<int> stk;
    stk.push(0);
    int size = input.size();
    for (int i = 0; i < size; i++) {
        if (input[i] == '~') {
            stk.top() *= (-1);
        } else if (input[i] == '+') {
            int a = stk.top();
            stk.pop();
            stk.top() += a;
        } else if (input[i] == '-') {
            int a = stk.top();
            stk.pop();
            stk.top() -= a;
        } else if (input[i] == '*') {
            int a = stk.top();
            stk.pop();
            stk.top() *= a;
        } else if (input[i] == '/') {
            int a = stk.top();
            stk.pop();
            stk.top() /= a;
        } else if (input[i] == ' ') stk.push(0);
        else {
            stk.top() = 10 * stk.top() + int(input[i]) - '0';
        }
    }
    return stk.top();
}

int main() {
    std::string input;
    std::string output;
    std::cin >> input;
    output = postfix(input);
    std::cout << output << std::endl;
    std::cout << post_calc(output);
    return 0;
}