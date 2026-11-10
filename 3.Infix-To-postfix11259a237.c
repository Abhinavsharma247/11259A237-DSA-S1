/*
 * Experiment 3: Infix to Postfix Conversion using Stack
 *
 * AIM:
 * To convert an infix expression into its equivalent postfix expression
 * by using a stack and operator precedence in C.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char operatorStack[MAX];
int stackTop = -1;

/* Add an operator to the stack when space is available. */
void push(char symbol)
{
    if (stackTop == MAX - 1)
    {
        printf("Error: Stack Overflow!\n");
        return;
    }

    operatorStack[++stackTop] = symbol;
}

/* Remove and return the top item from the stack. */
char pop(void)
{
    if (stackTop == -1)
    {
        printf("Error: Stack Underflow!\n");
        return '\0';
    }

    return operatorStack[stackTop--];
}

/* Read the top stack item without removing it. */
char peek(void)
{
    if (stackTop == -1)
    {
        return '\0';
    }

    return operatorStack[stackTop];
}

/* Assign a priority level to each supported operator. */
int getPrecedence(char symbol)
{
    switch (symbol)
    {
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

/* Return true when the given character is an arithmetic operator. */
int isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' ||
           symbol == '*' || symbol == '/' || symbol == '^';
}

/* Convert the supplied infix string into postfix notation. */
void convertToPostfix(char infix[], char postfix[])
{
    int outputIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char symbol = infix[i];

        /* Operands are copied directly to the result. */
        if (!isOperator(symbol) &&
            symbol != '(' && symbol != ')' &&
            symbol != '[' && symbol != ']' &&
            symbol != '{' && symbol != '}')
        {
            postfix[outputIndex++] = symbol;
        }
        /* Operators are arranged according to their precedence. */
        else if (isOperator(symbol))
        {
            while (stackTop != -1 &&
                   peek() != '(' &&
                   getPrecedence(peek()) >= getPrecedence(symbol))
            {
                postfix[outputIndex++] = pop();
            }

            push(symbol);
        }
        /* Save an opening parenthesis until its matching closing one. */
        else if (symbol == '(')
        {
            push(symbol);
        }
        /* Move operators out until the opening parenthesis is reached. */
        else if (symbol == ')')
        {
            while (stackTop != -1 && peek() != '(')
            {
                postfix[outputIndex++] = pop();
            }

            if (stackTop != -1)
            {
                pop();
            }
        }
    }

    /* Append any operators still waiting in the stack. */
    while (stackTop != -1)
    {
        postfix[outputIndex++] = pop();
    }

    postfix[outputIndex] = '\0';
}

int main(void)
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression (formula): ");
    scanf("%99s", infix);

    convertToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
