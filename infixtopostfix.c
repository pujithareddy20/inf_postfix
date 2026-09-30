#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
/* Push an element into stack */
void push(char ch)
{
if (top == MAX - 1)
{
printf("Stack Overflow\n");
return;
}


stack[++top] = ch;
}
/* Pop an element from stack */
char pop()
{
if (top == -1)
return '\0';

return stack[top--];
}
/* Return top element of stack */
char peek()
{
if (top == -1)
return '\0';

return stack[top];
}
/* Check whether character is an operator */
int isOperator(char ch)
{
return ch == '+' || ch == '-' ||
ch == '*' || ch == '/' ||
ch == '%' || ch == '^';
}
/* Return precedence of operator */
int precedence(char ch)
{
switch (ch)


{
case '+':
case '-':
return 1;

case '*':
case '/':
case '%':
return 2;

case '^':
return 3;
}

return 0;
}
/* Convert infix expression to postfix */
void infixToPostfix(char infix[], char postfix[])
{
int i, j = 0;
char ch;

for (i = 0; infix[i] != '\0'; i++)
{
ch = infix[i];

/* Ignore spaces */
if (isspace(ch))
continue;

/* Operand */
if (isalnum(ch))
{
postfix[j++] = ch;
}
/* Opening parenthesis */
else if (ch == '(')
{
push(ch);
}
/* Closing parenthesis */
else if (ch == ')')
{
while (top != -1 && peek() != '(')
{
postfix[j++] = pop();
}

if (top != -1 && peek() == '(')
pop();
}
/* Operator */
else if (isOperator(ch))
{
while (top != -1 &&
peek() != '(' &&
precedence(peek()) >= precedence(ch))
{


postfix[j++] = pop();
}
push(ch);
}
}
/* Pop remaining operators */
while (top != -1)
{
postfix[j++] = pop();
}
postfix[j] = '\0';
}
int main()
{
char infix[MAX];
char postfix[MAX];

printf("Enter infix expression: ");
fgets(infix, MAX, stdin);

infixToPostfix(infix, postfix);

printf("\nInfix Expression : %s", infix);
printf("Postfix Expression : %s\n", postfix);

return 0;
}

