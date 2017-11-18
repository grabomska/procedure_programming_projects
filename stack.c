#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101


typedef struct Stack
{
    int data[MAX];
    size_t size; /* monitoring elements of massive */
} Stack_t;


void push(Stack_t *stack, int value)
{
	 if (stack->size >= MAX) /*controlling overflow of stack */
	 {
		 fprintf(stderr, "Stack OverFlow");
		 exit(STACK_OVERFLOW);
	 }
	 else
		 stack->data[stack->size] = value;
     	 stack->size++;
}


int pop(Stack_t *stack) {
    if (stack->size == 0) /*if data[0] = '='*/
    {
    	fprintf(stderr, "Stack UnderFlow");
        exit(STACK_UNDERFLOW);
    }
    else
    	stack->size--;
    	return stack->data[stack->size];
}


int main()
{
	 Stack_t stack;
	 stack.size = 0; /*massive starts from zero*/
	 fprintf(stderr, "Please type your expression\n");
	     while (!feof(stdin))
	     {
	         int c = getchar();
	         int x;
	         switch (c)
	         {
	             case '\n':
	             case ' ' :  break;
	             case '=' :  printf("Result = %d\n", pop(&stack));
	             	 	 	 printf("For exit type any char or you can continue type expression\n"); break;
	             case '+' :  push(&stack, pop(&stack) + pop(&stack)); break;
	             case '-' :  push(&stack, -pop(&stack) + pop(&stack)); break;
	             case '*' :  push(&stack, pop(&stack) * pop(&stack)); break;
	             default:
	                 ungetc(c, stdin);
	                 if (scanf("%d", &x) != 1)
	                 {
	                     fprintf(stderr, "exit\n");
	                     return -1;
	                 } else
	                 {
	                     push(&stack, x);
	                 }
	                 break;
	          }
	    }
	return 0;
}

