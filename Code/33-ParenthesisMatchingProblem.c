/*
Author: Ashmit JaiSarita Gupta
Topic: Parenthesis Matching Problem
Date Created: 28-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *s) //O(1)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *s, char element) //O(1)
{

    // No Need To Check For Stack Overflow in this scenario. The size of stack = size of expression passed. So the number of parenthesis that has to be stored in stack will always be less than or equal to size of stack.

    s->arr[++s->top] = element;
}

int pop(struct Stack *s) // O(1)
{
    if (isEmpty(s))
    {
        return 0;
    }
    else
    {
        char popElement = s->arr[s->top--];
        return 1;
    }
}

int parenthesisMatch(char *exp)
{
    // Create And Initialize the stack
    struct Stack *sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        if (exp[i] == ')')
        {
            // Method 1
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    // // Method 1
    // if (isEmpty(sp))
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }

    //Method 2
    return isEmpty(sp);
}

int main()
{
    char *expression = "8*(9)())(";

    if (parenthesisMatch(expression))
    {
        printf("Expression is Valid! The Parenthesis is Matching.\n");
    }
    else
    {
        printf("Invalid Expression! The Parenthesis is not Matching.\n");
    }

    return 0;
}