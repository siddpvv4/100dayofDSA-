#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// --- Stack Implementation ---
char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// --- Helper Functions ---

// Function to return the precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// --- Main Conversion Logic ---
void infixToPostfix(char* infix) {
    int i, j = 0;
    char postfix[MAX];
    
    // Scan the infix expression from left to right
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // 1. If the character is an operand, add it to the output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // 2. If the character is '(', push it to the stack
        else if (ch == '(') {
            push(ch);
        }
        // 3. If the character is ')', pop and output until '(' is found
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove the '(' from the stack
        }
        // 4. If the character is an operator
        else if (isOperator(ch)) {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                // Special case for right-associative operator '^'
                if (ch == '^' && precedence(peek()) == precedence(ch)) {
                    break; 
                }
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    
    // 5. Pop all remaining operators from the stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    
    // Null-terminate the string
    postfix[j] = '\0';
    
    // Print the final postfix expression
    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];
    
    // Read the single-line infix expression
    if (scanf("%s", infix) == 1) {
        infixToPostfix(infix);
    }
    
    return 0;
}