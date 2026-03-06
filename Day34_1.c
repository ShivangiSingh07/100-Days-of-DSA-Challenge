/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            // Operand → push to stack
            push(&stack, atoi(token));
        } else {
            // Operator → pop two operands
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator: %c\n", token[0]);
                    exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

// Driver code
int main() {
    char expr[] = "2 3 1 * + 9 -";
    printf("Postfix Expression: %s\n", expr);
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    return 0;
}
