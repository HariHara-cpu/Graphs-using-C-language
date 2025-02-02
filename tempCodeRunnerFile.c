#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char b[100]; // Stack array
int top = -1; // Stack top index

// Function to check if a character is an operator
int isop(char a) {
    return (a == '+' || a == '-' || a == '*' || a == '/');
}

// Function to return the precedence of an operator
int prec(char a) {
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return 0;
}

// Function to push a character onto the stack
void push(char a) {
    top++;
    b[top] = a;
}

// Function to pop a character from the stack
char pop() {
    if (top != -1) {
        char x = b[top];
        top--;
        return x;
    }
    return '\0'; // Return null character if stack is empty
}

// Function to reverse a string
void reverse(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char in[100]; // Input infix expression
    char pre[100]; // Output prefix expression
    int i = 0;

    printf("Enter the infix expression: ");
    scanf("%s", in);

    reverse(in); // Reverse the infix expression

    int j = 0; // Index for prefix expression

    // Conversion from infix to prefix
    while (in[i] != '\0') {
        if (in[i] == ')')
            push(in[i]);
        else if (in[i] == '(') {
            // Pop until ')' is encountered
            while (b[top] != ')') {
                pre[j] = pop();
                j++;
            }
            pop(); // Remove ')'
        } else if (!isop(in[i])) {
            // If it's an operand, add to prefix expression
            pre[j] = in[i];
            j++;
        } else if (isop(in[i])) {
            // If it's an operator
            while (prec(in[i]) < prec(b[top]) && top != -1) {
                pre[j] = pop();
                j++;
            }
            push(in[i]);
        }
        i++;
    }

    // Pop remaining operators from stack to prefix expression
    while (top != -1) {
        pre[j] = pop();
        j++;
    }

    pre[j] = '\0'; // Null-terminate the prefix expression

    reverse(pre); // Reverse the prefix expression to get the final result

    printf("The prefix expression: %s\n", pre);

    return 0; // Return 0 to indicate successful execution
}
