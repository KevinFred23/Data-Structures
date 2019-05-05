//infix to postfix
#include<stdio.h>
typedef enum
{lparen,rparen,plus,minus,multi,div,mod,eos,operand}pre;
int isp[] = {0,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};
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
void printtoken(pre token)
{
	switch(token)
	{
		case lparen : printf("("); break;
		case rparen : printf(")"); break;
		case plus   : printf("+"); break;
	    case minus  : printf("-"); break;
	    case multi  : printf("*"); break;
	    case div    : printf("/"); break;
	    case mod    : printf("%");break;
	    case eos    : printf(" ");break;
	    case operand: break;
	}
}
void push(int token)
{
	stack[++top] = token;
}
int pop()
{
	return stack[top--];
}

void postfix()
{
	pre token;
	char sym;
	int n=0;
	stack[++top] = eos;
	for(token = gettoken(&sym,&n);token!=eos;token = gettoken(&sym,&n))
	{
		if(token==operand) printf("%c",sym);
		else if(token==rparen)
		{
			while(stack[top]!=lparen) printtoken(pop()); pop();
		}
		else{
		while(isp[stack[top]]>=icp[token]) printtoken(pop()); push(token);
		}
	}
	while((token=pop())!=eos) printtoken(token);
	printf("\n");
}

main()
{
	printf("Enter expression = ");
	scanf("%s",f);
	postfix();
}
