/*
Given a sequence of N round, square and curly brackets. Find out whether it is possible
to add numbers and arithmetic symbols to it so that a correct arithmetic expression is
obtained.
Restrictions:
1 <= N <= 100,000.
Input: The first line contains N number of brackets, the second line contains N characters
from the set (, ), [, ], {, }.
Output: The word "Yes" is displayed if it is possible to obtain the correct arithmetic
expression, or "No" if it is not. 
*/


#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isArithmeticExpressionPossible(int N, string brackets) {
    stack<char> s;
    for (int i = 0; i < N; i++) {
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            s.push(brackets[i]);
        } else {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            if ((brackets[i] == ')' && top == '(') || (brackets[i] == ']' && top == '[') || (brackets[i] == '}' && top == '{')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    int N;
    cin >> N;

    string brackets;
    cin >> brackets;

    if (isArithmeticExpressionPossible(N, brackets)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
