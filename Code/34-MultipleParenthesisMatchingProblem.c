/*
Author: Ashmit JaiSarita Gupta
Topic: Muliple Parenthesis Matching Problem
Date Created: 28-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *sp, char element)
{
    // No Need To Check For Stack Overflow in this scenario. The size of stack = size of expression passed. So the number of parenthesis that has to be stored in stack will always be less than or equal to size of stack.
    sp->arr[++sp->top] = element;
}

int pop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        return -1;
    }
    char popped = sp->arr[sp->top--];
    return popped;
}

int MultipleParenthesisMatch(char *exp)
{
    struct Stack *sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '<')
        {
            push(sp, exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']' || exp[i] == '>')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                char popped = pop(sp);
                if (exp[i] == ')' && popped != '(')
                {
                    return 0;
                }
                if (exp[i] == '}' && popped != '{')
                {
                    return 0;
                }
                if (exp[i] == ']' && popped != '[')
                {
                    return 0;
                }
                if (exp[i] == '>' && popped != '<')
                {
                    return 0;
                }
            }
        }
    }
    return isEmpty(sp);
}

int main()
{
    char *expression = "8(*(9){=(G[OO]D)-{a/b}}*[9+7])";

    if (MultipleParenthesisMatch(expression))
    {
        printf("Expression is Valid! The Parenthesis are balanced.\n");
    }
    else
    {
        printf("Invalid Expression! The Parenthesis are not balanced.\n");
    }

    return 0;
}