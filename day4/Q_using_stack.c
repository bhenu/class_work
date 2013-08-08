#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20
#define MAXOP 100

static struct STACK
{
    int stack[SIZE];
    int pos;
};


/* function prototypes for stack
 * both return 1 on success and
 * 0 on failure */
int push(int, struct STACK *);
int pop(int *, struct STACK *);
void display(struct STACK);
int fill_stack(struct STACK *);

/* function prototype for delete */
int delete(int *, struct STACK *);

/* function prototype for getop */
int getop(char [], int *, char []);

/* ######################### MAIN LOGIC ############################# */

int main(void)
{
	struct STACK stack_1, stack_2;
	/* initialize stack */
	stack_1.pos = stack_2.pos = -1;
	int value, poped; 				/* variabel to store value to be
									pushed and value that is poped*/
									
	int n = 25;						/* variable to store user input */
	
	while(n != 0)
    {
        printf("## 1: push to stack\n## 2: pop to stack\n## 3: display the stack\n## 4: insert into stack as queue\n## 5: delete from stack as queue\n## 0: quit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:	printf("Enter an integer to push\n");
                    scanf("%d", &value);
                    push(value, &stack_1);
                    break;
            case 2: pop(&poped, &stack_1);
					printf("%d poped\n", poped);
                    break;
            case 3: printf("Stack:");
					display(stack_1);
                    break;
            case 4: printf("Enter integer to insert\n");
                    scanf("%d", &value);
                    push(value, &stack_1);
                    break;
            case 5:	delete(&poped, &stack_1);
					printf("%d deleted\n", poped);
					break;
			default: printf("error: wrong input\n");
					break;
        }
    }
    return 0;
}



/* ###############################O################################## */


/* definition of stack functions */
int push(int value, struct STACK *mystack)
{
    if(mystack->pos < (SIZE -1))
    {
        mystack->stack[++(mystack->pos)] = value;
        return 1;
    }
    else
    {
        printf("error: stack is full\n");
        return 0;
    }
}

int pop(int *poped, struct STACK *mystack)
{
    if(mystack->pos > -1)
    {
        *poped = mystack->stack[(mystack->pos)--];
        return 1;
    }
    else
    {
        printf("error: Stack is empty\n");
        return 0;
    }
}

void display(struct STACK mystack)
{
    int i = 0;
    while (i <= mystack.pos)
        printf("%d ", mystack.stack[i++]);
    printf("\n");
}

/* definition of getop function */
int getop(char string[], int *idx, char op[])
{
    char c;     /* temp variable to store current char */
    int i;

    while ((op[0] = c = string[(*idx)++]) == ' ' || c == '\t')
    /* loop through spaces */
        ;
    op[1] = '\0';

    if (!isdigit(c) && c != '.') /* not a number or decimal point */
        return 0;

    i = 0;
    if (isdigit(c))
        while (isdigit(op[++i] = c = string[(*idx)++]))
            ;
    if (c == '.')
        while (isdigit(op[++i] = c = string[(*idx)++]))
            ;
    op[i] = '\0';

    if(c != '\0')
        (*idx)--;

    return 1;
}

/* function to take input into the stacks */
int fill_stack(struct STACK *mystack)
{
    char input[MAXOP], op[20];
    int type, indx = 0;

    printf("Enter elements of the stack [type int] seperated by a space:\n");
    fgets(input, MAXOP, stdin);

    type = getop(input, &indx, op);
    while(op[0] != '\0')
    {
        if (type)
            push(atoi(op), mystack);

        type = getop(input, &indx, op);
    }

    return 1;
}

/* function to delete from stack as queue */
int delete(int * deleted, struct STACK * given_stack)
{
	int poped; 
	struct STACK stack_2;
	stack_2.pos = -1;
	
	while(given_stack->pos > 0)
	{
		pop(&poped, given_stack);
		push(poped, &stack_2);
	}
	
	pop(&poped, given_stack);
	*deleted = poped;
	
	while(pop(&poped, &stack_2))
	{
		push(poped, given_stack);
	}
	
	return 1;
} 
