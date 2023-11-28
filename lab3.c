#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE];

void initialize() {
    top = -1;
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(char item) {
    if (!isFull()) {
        stack[++top] = item;
    } else {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

char peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

int isOperand(char symbol) {
    return (symbol >= '0' && symbol <= '9');
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char *infixExpression, char *postfixExpression) {
    initialize();

    int i, j = 0;
    for (i = 0; infixExpression[i] != '\0'; i++) {
        char symbol = infixExpression[i];

        if (isOperand(symbol)) {
            postfixExpression[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (!isEmpty() && peek() != '(') {
                postfixExpression[j++] = pop();
            }
            pop(); 
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(symbol)) {
                postfixExpression[j++] = pop();
            }
            push(symbol);
        }
    }

    while (!isEmpty()) {
        postfixExpression[j++] = pop();
    }

    postfixExpression[j] = '\0'; 
}

int evaluatePostfix(char *postfixExpression) {
    initialize();

    int i;
    for (i = 0; postfixExpression[i] != '\0'; i++) {
        char symbol = postfixExpression[i];

        if (isOperand(symbol)) {
            push(symbol - '0'); // Convert char to int
        } else {
            int operand2 = pop();
            int operand1 = pop();

            switch (symbol) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", symbol);
                    exit(EXIT_FAILURE);
            }
        }
    }

    return pop();
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];
    int choice;

    do {
        printf("\n==== Infix to Postfix Conversion and Evaluation ====\n");
        printf("1. Enter Infix Expression\n");
        printf("2. Convert to Postfix and Evaluate\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an infix expression: ");
                getchar(); 
                fgets(infixExpression, MAX_SIZE, stdin);
                infixExpression[strcspn(infixExpression, "\n")] = '\0'; 
                break;
            case 2:
                infixToPostfix(infixExpression, postfixExpression);
                printf("Postfix expression: %s\n", postfixExpression);
                printf("Evaluation result: %d\n", evaluatePostfix(postfixExpression));
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
