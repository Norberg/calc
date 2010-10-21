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
