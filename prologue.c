#include<stdio.h>

//Stack functions
void push(int top, int *stack, int *current)
{
	stack[*current+1] = top;
	*current = *current + 1;
}
int pop(int *stack, int *current) 
{
	int temp = -1;
	
	if(*current <= 0) 
	{
		printf("Fail, there is no content on the stack that can be pop'ed \n");
	}
	else 
	{
		temp = stack[*current];
		*current = *current - 1;
	}

	return temp;
}

int main() {

	int stack[32];
	int current = -1;
	int a,b,c,d,e,f,g,h,i,j,l,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	int ecx;
