#include <iostream>
#include <stack>
#include <cctype> // For isdigit
#include <string>
using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (char ch : infix) {
        if (isdigit(ch) || isalpha(ch)) { // Operand
            postfix += ch;
        } else if (ch == '(') { // Left parenthesis
            s.push(ch);
        } else if (ch == ')') { // Right parenthesis
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') s.pop();
        } else if (isOperator(ch)) { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (isdigit(ch)) { // Operand
            s.push(ch - '0'); // Convert char to int
        } else if (isOperator(ch)) { // Operator
            if (s.size() < 2) {
                throw invalid_argument("Invalid postfix expression");
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': 
                    if (b == 0) throw invalid_argument("Division by zero");
                    s.push(a / b); 
                    break;
                default: throw invalid_argument("Unexpected operator");
            }
        }
    }

    if (s.size() != 1) {
        throw invalid_argument("Invalid postfix expression");
    }

    return s.top();
}

int main() {
    string infix;
    cout << "Enter a valid infix expression: ";
    cin >> infix;

    try {
        string postfix = infixToPostfix(infix);
        cout << "Postfix expression: " << postfix << endl;

        int result = evaluatePostfix(postfix);
        cout << "Result of postfix evaluation: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
