#include <iostream>
#include <string>
using namespace std;

int st[20]; 
int top = -1; 

void push(int x) {
    st[++top] = x; 
}

int pop() {
    return st[top--]; 
}

int evaluatePostfixExpression(string expression) {
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (isdigit(c)) {
            int temp = (c - '0');
            push(temp);
        } else {
            int op2 = pop();
            int op1 = pop();
            switch (c) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                
            }
        }
    }
    return st[top];
}

int main() {
    string expression;
    cout << "Enter postfix expression to evaluate: ";
    getline(cin, expression);
    cout << "The answer is: " << evaluatePostfixExpression(expression) << endl;
    return 0;
}

