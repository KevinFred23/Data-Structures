//postfix evaluation
#include<stdio.h>

typedef enum
{lparen,rparen,plus,minus,multi,div,mod,eos,operand}pre;

int stack[100];
char f[100];
int top=-1;

pre gettoken(char *sym,int *n)
{
	*sym = f[(*n)++];
	switch(*sym)
	{
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return plus;
		case '-' : return minus;
		case '*' : return multi;
		case '/' : return div;
		case '%' : return mod;
		case '\0': return eos;
	 	default  : return operand;
	}
}

void push(int item)
{
	stack[++top] = item;
}

int pop()
{
	return stack[top--];
}

int eval()
{
	pre token;
	char sym;
	int op1,op2,n=0;
	token = gettoken(&sym,&n);
	while(token!=eos)
	{
		if(token==operand) push(sym-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
				case lparen : break;
				case rparen : break;
				case plus   : push(op1+op2);
				case minus  : push(op1-op2);
				case multi  : push(op1*op2);
				case div    : push(op1/op2);
				case mod    : push(op1%op2);
				case eos    : break;
				case operand: break;
			}
		}
		token = gettoken(&sym,&n);
	}
	return pop();
}

main()
{
	printf("Enter Expression - ");
	scanf("%s",f);
	printf("%d",eval());
}
