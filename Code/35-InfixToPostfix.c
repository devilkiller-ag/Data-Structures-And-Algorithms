/*
Author: Ashmit JaiSarita Gupta
Topic: Infix to postfix expression using stack
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

int isFull(struct Stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *sp, char element)
{
    // No Need To Check For Stack Overflow in this scenario. The size of stack = size of expression passed. So the number of operators that has to be stored in stack will always be less than or equal to size of stack.
    sp->arr[++sp->top] = element;
}

char pop(struct Stack *s) // O(1)
{
    if (isEmpty(s))
    {
        printf("Pop() failed! Stack Underflow (Stack is Empty).\n");
        return -1;
    }
    else
    {
        char popElement = s->arr[s->top--];
        return popElement;
    }
}

char stackTop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        return '0';
    }
    char top = sp->arr[sp->top];
    return top;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 3;
    }
    else if (op == '+' || op == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

// Method 2 = By Harry Bhai
char *infixToPostfix(char *infix)
{
    int length = strlen(infix);
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((length + 1) * sizeof(char));
    int i, j = 0; // i = Tracks infix Traversal; j = tracks postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i++]);
            }
            else
            {
                postfix[j++] = pop(sp);
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j++] = pop(sp);
    }
    postfix[j] = '\0';
    return postfix;
}

//Method 1 = By me - Not working at Last popping stack
void postfix(char *exp)
{
    int length = strlen(exp);
    char post[length + 1];
    // char *post = (char *)malloc((length + 1) * sizeof(char));
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i, counter = 0; // i = infix scanner; counter = postfix filller
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/')
        {
            post[counter++] = exp[i];
        }
        else
        {
            if (exp[i] == '+' && stackTop(sp) != '*' && stackTop(sp) != '/' && stackTop(sp) != '+' && stackTop(sp) != '-')
            {
                push(sp, '+');
                continue;
            }
            if (exp[i] == '-' && stackTop(sp) != '*' && stackTop(sp) != '/' && stackTop(sp) != '+' && stackTop(sp) != '-')
            {
                push(sp, '-');
                continue;
            }
            if (exp[i] == '*' && stackTop(sp) != '*' && stackTop(sp) != '/')
            {
                push(sp, '*');
                continue;
            }
            if (exp[i] == '/' && stackTop(sp) != '*' && stackTop(sp) != '/')
            {
                push(sp, '/');
                continue;
            }
            while ((exp[i] == '-' || exp[i] == '+') && (stackTop(sp) == '*' || stackTop(sp) == '/' || stackTop(sp) == '+' || stackTop(sp) == '-'))
            {
                if (isEmpty(sp))
                {
                    push(sp, exp[i]);
                    break;
                }
                else
                {
                    post[counter++] = pop(sp);
                }
            }
            while ((exp[i] == '*' || exp[i] == '/') && (stackTop(sp) == '*' || stackTop(sp) == '/'))
            {
                if (isEmpty(sp) || stackTop(sp) == '+' || stackTop(sp) == '-')
                {
                    push(sp, exp[i]);
                    break;
                }
                else
                {
                    post[counter++] = pop(sp);
                }
            }
        }
    }
    while (!isEmpty(sp))
    {
        post[counter++] = pop(sp);
        printf("%d\n", counter);
    }
    post[counter] = '\0';
    printf("%s\n", post);
}

int main()
{
    char *expression1 = "a-b*d+c";
    postfix(expression1);

    char *expression2 = "m-n*p+q";
    printf("Postfix is %s\n", infixToPostfix(expression2));

    return 0;
}