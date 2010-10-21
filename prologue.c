#include<stdio.h>

int current = -1;
int stack[32];

//Stack functions
void push(int top)
{
	stack[current+1] = top;
	current = current + 1;
}
int pop() 
{
	int temp = -1;
	
	if(current < 0) 
	{
		printf("Fail, there is no content on the stack that can be pop'ed \n");
	}
	else 
	{
		temp = stack[current];
		current = current - 1;
	}

	return temp;
}
void add() 
{
	int x = pop();
	int y = pop();
	push(x+y);
}
void sub()
{
	int x = pop();
	int y = pop();
	push(x-y);
}
void print()
{
	printf("%d \n", pop());
}
void div()
{
	int x = pop();
	int y = pop();
	push(x/y);
}
void mul()
{
	int x = pop();
	int y = pop();
	push(x*y);
}
void neg()
{
	int x = pop();
	push(-x);
}
void NE()
{
	int x = pop();
	int y = pop();
	if (x != y)
	{
		push(1);
	}
	else
	{
		push(0);
	}
}
void EQ() 
{
	int x = pop();
	int y = pop();
	if (x == y)
	{
		push(1);
	}
	else
	{
		push(0);
	}
}
void LE() 
{
	int x = pop();
	int y = pop();
	if (y <= x)
	{
		push(1);
	}
	else
	{
		push(0);
	}
}
void GE() 
{
	int x = pop();
	int y = pop();
	if (y >= x)
	{
		push(1);
	}
	else
	{
		push(0);
	}
}
void LESS() 
{
	int x = pop();
	int y = pop();
	if (y < x)
	{
		push(1);
	}
	else
	{
		push(0);
	}
}
void GREATER() 
{
	int x = pop();
	int y = pop();
	if (y > x)
	{
		push(1);
	}
	else
	{
		push(0);
	}
}
void gcd()
{
int a = pop();
int b = pop();

while(a != b) {
  if(a > b) {
    a=a-b;
  } else {
    b=b-a;
  }
}

push(a);

}
void fact() 
{
	int a = pop();
	int b = a;
	while (b > 0)
	{
		a = a * b;
		b--;
	}
	push(a);
}
void lntwo()
{
	int a = pop();
	int b = 1;
	while(b < a)
	{
		b = b * 2;
	}
	if(a == 0)
	{
		b = 1;
	}
	push(b);
}

int main() 
{

	int a,b,c,d,e,f,g,h,i,j,l,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
