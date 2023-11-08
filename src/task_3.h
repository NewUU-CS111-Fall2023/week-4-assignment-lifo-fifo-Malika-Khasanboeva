// Task 3 

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfixExpression(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    string exp;
    getline(cin, exp);

    cout << evaluatePostfixExpression(exp) << endl;

    return 0;
}
