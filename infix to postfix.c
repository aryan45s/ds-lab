#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

// Function prototypes
void push(char elem);
char pop();
int precedence(char op);

int main()
{
    char infix[SIZE], postfix[SIZE];
    char ch, temp;
    int i = 0, j = 0;
    
    printf("Enter a valid infix expression (single char operands): ");
    scanf("%s", infix);
    
    // Initialize stack with '#' as bottom marker
    push('#');
    
    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum(ch))  // If operand
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')  // Left parenthesis
        {
            push(ch);
        }
        else if (ch == ')')  // Right parenthesis
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            temp = pop();  // Remove '('
        }
        else  // Operator
        {
            while (precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    
    // Pop all remaining operators
    while (stack[top] != '#')
    {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';  // Null terminate string
    printf("\nPostfix Expression: %s\n", postfix);
    
    return 0;
}

// Push character onto stack
void push(char elem)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow!\n");
        return;
    }
    stack[++top] = elem;
}

// Pop character from stack
char pop()
{
    if (top < 0)
    {
        printf("\nStack Underflow!\n");
        return '#';
    }
    return stack[top--];
}

// Get operator precedence
int precedence(char op)
{
    switch (op)
    {
        case '^': return 4;  // Highest precedence
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        case '(': return 1;  // Lowest when in stack
        case '#': return 0;  // Bottom marker
        default: return 0;
    }
}
