/*
 * Experiment 4: Postfix Expression Evaluation using Stack
 *
 * AIM:
 * To evaluate a postfix expression containing integer operands and
 * arithmetic operators by using a stack in C.
 */

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int valueStack[MAX];
int stackTop = -1;

/* Store a value at the current top of the stack. */
void push(int value)
{
    valueStack[++stackTop] = value;
}

/* Retrieve the most recently stored value from the stack. */
int pop(void)
{
    return valueStack[stackTop--];
}

int main(void)
{
    char expression[MAX];
    int readingNumber = 0;
    int number = 0;
    int leftOperand, rightOperand, answer;

    printf("Enter postfix expression (digits & operators, space separated): ");
    fgets(expression, MAX, stdin);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char token = expression[i];

        /* Combine consecutive digits to form a complete integer. */
        if (isdigit((unsigned char)token))
        {
            number = number * 10 + (token - '0');
            readingNumber = 1;
        }
        /* A separator marks the end of the number being read. */
        else if ((token == ' ' || token == '\n') && readingNumber)
        {
            push(number);
            number = 0;
            readingNumber = 0;
        }
        /* Apply an operator to the two latest values in the stack. */
        else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            rightOperand = pop();
            leftOperand = pop();

            switch (token)
            {
                case '+':
                    answer = leftOperand + rightOperand;
                    break;

                case '-':
                    answer = leftOperand - rightOperand;
                    break;

                case '*':
                    answer = leftOperand * rightOperand;
                    break;

                case '/':
                    answer = leftOperand / rightOperand;
                    break;

                default:
                    answer = 0;
            }

            push(answer);
        }
    }

    printf("Result of postfix evaluation = %d\n", pop());

    return 0;
}
