#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 100;

struct Stack {
    char data[MAXSIZE];
    int top;

    Stack() : top(-1) {}
};

void push(Stack& s, char item) {
    if (s.top == MAXSIZE - 1) {
        cout << "\nThe stack is full." << endl;
        return;
    }
    s.data[++s.top] = item;
}

char pop(Stack& s) {
    if (s.top == -1) {
        cout << "\nThe stack is empty. Invalid infix expression." << endl;
        return '#';
    }
    return s.data[s.top--];
}

int prec(char symbol) {
    switch (symbol) {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 4;
        default:
            return 0;
    }
}

void infixToPostfix(const char infix[]) {
    Stack s;
    char postfix[MAXSIZE];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; ++i) {
        char ch = infix[i];

        if (ch == ' ') {
            continue;
        }

        if (prec(ch) == 0) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(s, ch);
        } else if (ch == ')') {
            while (s.top != -1 && s.data[s.top] != '(') {
                postfix[j++] = pop(s);
            }
            if (s.top != -1) {
                pop(s);
            }
        } else {
            while (s.top != -1 && s.data[s.top] != '(' && prec(s.data[s.top]) >= prec(ch)) {
                postfix[j++] = pop(s);
            }
            push(s, ch);
        }
    }

    while (s.top != -1) {
        if (s.data[s.top] == '(') {
            pop(s);
        } else {
            postfix[j++] = pop(s);
        }
    }

    postfix[j] = '\0';

    cout << "\nThe postfix expression is = " << postfix << endl;
}

int main() {
    char choice;
    char infix[MAXSIZE];

    do {
        cout << "\n\nEnter the infix expression = ";
        cin.getline(infix, MAXSIZE);

        infixToPostfix(infix);

        cout << "\nDo you want to continue (Y/y) = ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'Y' || choice == 'y');

    return 0;
}